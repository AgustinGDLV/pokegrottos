#ifndef GUARD_PATHFINDING_H
#define GUARD_PATHFINDING_H

#define MAX_PATH 100    // Max final path size
#define MAX_NODES 500   // Max size of the queues

// Weight of the Heuristic, 0 for Dijkstra Algoritmin (Uniform Cost Search), 1 for A*, and >>1 for Greedy Best First Search
#define HEUR_WEIGHT 1

typedef struct Node {
    int state;
    struct Coords16 coords;
    int cost;
    u8 currentElevation;
    int path[MAX_PATH];
} Node;

typedef struct Set {
    unsigned int size;
    int value[MAX_NODES];
} Set;

typedef struct PriorityQueue {
    unsigned int size;
    float priority[MAX_NODES];
    struct Node value[MAX_NODES];
} PriorityQueue;

u8* GetMovesTowardsPlayer(struct ObjectEvent *objectEvent);
u8 GetFirstMoveTowardsPlayer(struct ObjectEvent *objectEvent);

#endif // GUARD_PATHFINDING_H