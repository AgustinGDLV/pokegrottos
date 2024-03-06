#include "global.h"
#include "data_util.h"
#include "random.h"

void ZeroQueue(struct Queue* queue)
{
    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;
    memset(queue->arr, 0, sizeof(queue->arr));
}

void Enqueue(struct Queue* queue, u8 item)
{
    if (queue->size == MAX_QUEUE_SIZE)
        return;
    queue->arr[queue->rear] = item;
    queue->rear += 1;
    queue->size += 1;
}

u8 Dequeue(struct Queue* queue)
{
    u8 item;
    u32 i;
    if (queue->size == 0)
        return 0;

    item = queue->arr[queue->front];
    for (i = 0; i < queue->rear - 1; ++i)
    {
        queue->arr[i] = queue->arr[i + 1];
    }
    queue->rear -= 1;
    queue->size -= 1;
    return item;
}

void DebugPrintQueue(struct Queue* queue)
{
    u32 i;
    DebugPrintf("Queue:");
    for (i = 0; i < queue->size; ++i)
        DebugPrintf("%d: %d", i, queue->arr[queue->front + i]);
}

void ZeroStack(struct Stack* stack)
{
    stack->top = 0;
    memset(stack->arr, 0, sizeof(stack->arr));
}

void Push(struct Stack* stack, u8 item)
{
    if (stack->top >= MAX_STACK_SIZE)
        return;
    stack->arr[stack->top] = item;
    stack->top += 1;
}

u8 Pop(struct Stack* stack)
{
    u8 item;
    if (stack->top == 0)
        return 0;
    stack->top -= 1;
    item = stack->arr[stack->top];
    return item;
}

// Returns the total weight of a weighted pool.
u16 GetPoolTotalWeight(const struct WeightedElement *pool)
{
    u32 i, weight = 0;
    for (i = 0; i < MAX_WEIGHTED_POOL_SIZE; ++i)
    {
        if (pool[i].item > 0)
            weight += pool[i].weight;
        else
            break;
    }
    return weight;
}

// Returns an element from a weighted pool.
u16 ChooseElementFromPool(const struct WeightedElement* pool)
{
    u32 i, rand;
    u32 totalWeight = GetPoolTotalWeight(pool);

    // Generates a value within total weight and finds corresponding item.
    rand = RandomF() % totalWeight;
    for (i = 0; i < MAX_WEIGHTED_POOL_SIZE; ++i)
    {
        if (rand > pool[i].weight)
            rand -= pool[i].weight;
        else
            return pool[i].item;
    }

    // This shouldn't be reached, but just in case.
    return 0;
}
