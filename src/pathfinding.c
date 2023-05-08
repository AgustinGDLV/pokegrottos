#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "fieldmap.h"
#include "main.h"
#include "malloc.h"
#include "overworld.h"
#include "palette.h"
#include "pathfinding.h"
#include "random.h"
#include "script.h"
#include "script_movement.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_specials.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"
#include "constants/maps.h"

// Code from Doctor Juanjo at https://www.pokecommunity.com/showthread.php?t=445293.

// apparently unrelated to the battle MOVES_COUNT
#define MOVES_COUNT 4

static const struct Coords16 sMoves[] = 
{
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
};

static const u32 sMoves_Walk[] = 
{
    MOVEMENT_ACTION_WALK_NORMAL_DOWN, 
    MOVEMENT_ACTION_WALK_NORMAL_UP,
    MOVEMENT_ACTION_WALK_NORMAL_LEFT, 
    MOVEMENT_ACTION_WALK_NORMAL_RIGHT,
    MOVEMENT_ACTION_FACE_DOWN,
    MOVEMENT_ACTION_FACE_UP,
    MOVEMENT_ACTION_FACE_LEFT,
    MOVEMENT_ACTION_FACE_RIGHT,
};

static void SwapNode(struct Node *a, struct Node *b);
static void Swap(float *a, float *b);
static u32 Abs(s32 x);
static u32 L1Distance(s32 x0, s32 y0, s32 xf, s32 yf);
static float CalcHeuristic(struct Node *node, s32 xGoal, s32 yGoal);
static bool32 IsInSet(struct Set *set, int num);
static void InsertIntoSet(struct Set *set, int num);
static void Heapify(struct PriorityQueue *queue, int i);
static int IsInQueue(struct PriorityQueue *queue, int num);
static void IsInQueueWithHigherPath(struct PriorityQueue *queue, struct Node newNode);
static void InsertIntoPriorityQueue(struct PriorityQueue *queue, struct Node newNode, int heuristic);
static struct Node Pop(struct PriorityQueue *queue, int i);
static u8 GetElevation(u8 prevZ, s16 x, s16 y);
static void GetChild(struct Node parent, int move, struct Node *child);
static void GetSolution(struct Node *node);
static bool32 IsMoveNotPossible(struct ObjectEvent *objectEvent, s16 x, s16 y, u32 dir, u8 currentElevation, bool32 ignorePlayer);
static bool32 GetPathToCoord(struct ObjectEvent *objectEvent, s32 x, s32 y, s32 facing, bool32 lookForPlayer);

static EWRAM_DATA u8 *sSolutionPath = NULL;

static void SwapNode(struct Node *a, struct Node *b)
{
    Node temp = *b;
    *b = *a;
    *a = temp;
}

static void Swap(float *a, float *b)
{
    float temp = *b;
    *b = *a;
    *a = temp;
}

static u32 Abs(s32 x)
{
    return (u32) ((x<0)?-x:x); // I don't know what this is
}

// Manhattan distance used as heuristic.
static u32 L1Distance(s32 x0, s32 y0, s32 xf, s32 yf)
{
    return Abs(x0 - xf) + Abs(y0 - yf);
}

static float CalcHeuristic(struct Node *node, s32 xGoal, s32 yGoal)
{
    float heuristic = HEUR_WEIGHT * L1Distance(node->coords.x, node->coords.y, xGoal, yGoal);
    heuristic *= (1.0 + 1/MAX_PATH); // For breaking ties
    return heuristic;
}

// Function to InsertIntoPriorityQueue to set.
static bool32 IsInSet(struct Set *set, int num)
{
    int i;
    for (i = 0; i< set->size; i++)
    {
        if (set->value[i]==num)
            return TRUE;
    }
    return FALSE;
}

static void InsertIntoSet(struct Set *set, int num)
{
    if (!IsInSet(set,num))
    {
        set->value[set->size] = num;
        set->size += 1;
    }
}

// Function to Heapify the tree.
static void Heapify(struct PriorityQueue *queue, int i)
{
    if (queue->size == 1)
    {
        // printf("Single element in the heap");
    }
    else
    {
        // Find the shortest among root, left child and right child.
        int shortest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < queue->size && queue->priority[l] < queue->priority[shortest])
            shortest = l;
        if (r < queue->size && queue->priority[r] < queue->priority[shortest])
            shortest = r;

        // Swap and continue heapifying if root is not shortest.
        if (shortest != i)
        {
            Swap(&(queue->priority[i]), &(queue->priority[shortest]));
            SwapNode(&(queue->value[i]), &(queue->value[shortest]));
            // Swap(&queue, i, shortest);
            Heapify(queue, shortest);
        }
    }
}

static int IsInQueue(struct PriorityQueue *queue, int num)
{
    int i;
    for (i = 0; i < queue->size; ++i)
    {
        if (queue->value[i].state == num)
            return TRUE;
    }
    return FALSE;
}

static void IsInQueueWithHigherPath(struct PriorityQueue *queue, struct Node newNode)
{
    int i;
    int j;
    for (i = 0; i< queue->size; i++)
    {
        if (queue->value[i].state == newNode.state && queue->value[i].cost > newNode.cost)
        {
            queue->priority[i] -= queue->value[i].cost - newNode.cost;
            queue->value[queue->size] = newNode;
            for (j = queue->size / 2 - 1; j >= 0; --j) 
                Heapify(queue, j);
            return;
        }
    }
}

// Function to insert an element into the tree.
static void InsertIntoPriorityQueue(struct PriorityQueue *queue, struct Node newNode, int heuristic)
{
    int i;
    if (queue->size == 0)
    {
        queue->priority[0] = newNode.cost + heuristic;
        queue->value[0] = newNode;
        queue->size += 1;
    }
    else
    {
        queue->priority[queue->size] = newNode.cost + heuristic;
        queue->value[queue->size] = newNode;
        queue->size += 1;
        for (i = queue->size / 2 - 1; i >= 0; --i)
            Heapify(queue, i);
    }
}


static struct Node Pop(struct PriorityQueue *queue, int i)
{
    struct Node element = queue->value[i];
    SwapNode(&(queue->value[i]), &(queue->value[queue->size - 1]));
    Swap(&(queue->priority[i]), &(queue->priority[queue->size - 1]));
    queue->size -= 1;
    for (i = queue->size / 2 - 1; i >= 0; --i)
        Heapify(queue, i);
    return element;
}

static u8 GetElevation(u8 prevZ, s16 x, s16 y)
{
    u8 mapZ;
    mapZ = MapGridGetElevationAt(x + 7, y + 7);
    if (mapZ == 0xF)
        return prevZ;
    else
        return mapZ;
}

static void GetChild(struct Node parent, int move, struct Node *child)
{
    int i;
    child->coords.x = parent.coords.x + sMoves[move].x;
    child->coords.y = parent.coords.y + sMoves[move].y;
    child->cost = parent.cost + 1;
    for(i = 0; i < parent.cost; i++)
    {
        child->path[i] = parent.path[i];
    }
    child->path[parent.cost] = move;
    child->currentElevation = GetElevation(parent.currentElevation, parent.coords.x, parent.coords.y);
}

static void GetSolution(struct Node *node)
{
    int i;
    sSolutionPath = AllocZeroed(node->cost + 1);
    for (i = 0; i < node->cost; ++i)
    {
        sSolutionPath[i] = sMoves_Walk[node->path[i]];
    }
    sSolutionPath[node->cost] = MOVEMENT_ACTION_STEP_END;
}

static bool32 IsMoveNotPossible(struct ObjectEvent *objectEvent, s16 x, s16 y, u32 dir, u8 currentElevation, bool32 ignorePlayer)
{
    if (x == gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x - MAP_OFFSET
        && y == gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y - MAP_OFFSET
        && ignorePlayer)
    {
        return COLLISION_NONE;
    }
    return CheckCollisionAtCoords(objectEvent, x + MAP_OFFSET, y + MAP_OFFSET, dir + 1, currentElevation);
}

static bool32 GetPathToCoord(struct ObjectEvent *objectEvent, s32 x, s32 y, s32 facing, bool32 lookForPlayer)
{
    Node startNode;
    PriorityQueue frontier;
    Set explored;
    Node child;
    Node node;
    u32 MapWidth = GetMapLayout()->width;

    int failure;
    int i;
    int childState;

    explored.size = 0;
    frontier.size = 0;

    failure = 0;

    startNode.coords.x = objectEvent->currentCoords.x - MAP_OFFSET;
    startNode.coords.y = objectEvent->currentCoords.y - MAP_OFFSET;
    startNode.state = startNode.coords.x + MapWidth * startNode.coords.y;
    startNode.cost = 0;
    startNode.currentElevation = GetElevation(objectEvent->currentElevation,startNode.coords.x,startNode.coords.y);

    InsertIntoPriorityQueue(&frontier, startNode, CalcHeuristic(&child, x, y));

    while (frontier.size > 0)
    {
        node = Pop(&frontier, 0);

        // Success! 
        // Currently hijacking the old way of returning the whole solution path because
        // I just need one movement action.
        if(node.coords.x == x && node.coords.y == y)
        {
            // GetSolution(&node);
            // return TRUE;
            return sMoves_Walk[node.path[0]];
        }
        InsertIntoSet(&explored, node.state);

        if(node.cost > 4)
            continue;

        for(i = 0; i < MOVES_COUNT; ++i)
        {
            if ((node.cost == 0 || !(i + node.path[node.cost - 1] == 1 || i + node.path[node.cost - 1] == 5))
                && !IsMoveNotPossible(objectEvent,node.coords.x + sMoves[i].x, node.coords.y + sMoves[i].y, i, node.currentElevation, lookForPlayer))
            {
                GetChild(node, i, &child);
                childState = child.coords.x + MapWidth * child.coords.y; 
                child.state = childState;

                // Add facing move if needed.
                if (child.coords.x == x && child.coords.y == y && i != facing)
                    child.path[child.cost] = facing + MOVES_COUNT;
                    child.cost = child.cost + 1;
            }

            if (!(IsInSet(&explored, childState) || IsInQueue(&frontier, childState))
                && frontier.size < MAX_NODES)
            {
                InsertIntoPriorityQueue(&frontier, child, CalcHeuristic(&child, x, y));
            }
            else if (IsInQueue(&frontier, childState))
            {
                IsInQueueWithHigherPath(&frontier, child);
            }
        }
    }
    DebugPrintf("No path found :(");
    return FALSE;
}

// Returns the first move in the shortest path towards the player.
u8 GetFirstMoveTowardsPlayer(struct ObjectEvent *objectEvent)
{
    s32 x, y;
    u8 retVal;
    x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
    retVal = GetPathToCoord(objectEvent, x - MAP_OFFSET, y - MAP_OFFSET, objectEvent->facingDirection, TRUE);
    if (retVal == FALSE)
    {
        // Return a random valid direction if there was not a path found.
        do {
            retVal = MOVEMENT_ACTION_WALK_NORMAL_DOWN + Random() % 3;
        } while (GetCollisionInDirection(objectEvent, retVal - MOVEMENT_ACTION_WALK_NORMAL_DOWN + 1));
    }
    DebugPrintf("Pathfinding!");
    return retVal;
}

#undef MOVES_COUNT
