#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stddef.h>
#include <stdbool.h>

/* Dynamic array */
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} IntVector;

bool vector_init(IntVector *vector, size_t initial_capacity);
void vector_destroy(IntVector *vector);
bool vector_push(IntVector *vector, int value);
bool vector_pop(IntVector *vector, int *value);
bool vector_get(const IntVector *vector, size_t index, int *value);

/* Singly linked list */
typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
    size_t size;
} IntList;

void list_init(IntList *list);
bool list_push_front(IntList *list, int value);
bool list_push_back(IntList *list, int value);
bool list_pop_front(IntList *list, int *value);
bool list_find(const IntList *list, int value);
void list_destroy(IntList *list);

/* Stack */
typedef IntVector IntStack;
bool stack_init(IntStack *stack, size_t initial_capacity);
void stack_destroy(IntStack *stack);
bool stack_push(IntStack *stack, int value);
bool stack_pop(IntStack *stack, int *value);
bool stack_peek(const IntStack *stack, int *value);

/* Queue */
typedef struct {
    ListNode *front;
    ListNode *back;
    size_t size;
} IntQueue;

void queue_init(IntQueue *queue);
bool queue_enqueue(IntQueue *queue, int value);
bool queue_dequeue(IntQueue *queue, int *value);
bool queue_peek(const IntQueue *queue, int *value);
void queue_destroy(IntQueue *queue);

#endif
