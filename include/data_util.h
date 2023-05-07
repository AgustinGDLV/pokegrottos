#ifndef GUARD_DATA_UTIL_H
#define GUARD_DATA_UTIL_H

#define MAX_QUEUE_SIZE      20
#define MAX_STACK_SIZE      10

struct Queue {
    u8 front;
    u8 rear;
    u8 size;
    u8 arr[MAX_QUEUE_SIZE];
};

struct Stack {
    u8 top;
    u8 arr[MAX_STACK_SIZE];
};

void ZeroQueue(struct Queue* queue);
void Enqueue(struct Queue* queue, u8 item);
u8 Dequeue(struct Queue* queue);
void DebugPrintQueue(struct Queue* queue);
void ZeroStack(struct Stack* stack);
void Push(struct Stack* stack, u8 item);
u8 Pop(struct Stack* stack);

#endif