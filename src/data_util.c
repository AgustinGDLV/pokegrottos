#include "global.h"
#include "data_util.h"

void ZeroQueue(struct Queue* queue)
{
    u32 i;
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
    u32 i;
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
