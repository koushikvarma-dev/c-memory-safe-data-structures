#include "data_structures.h"

#include <limits.h>
#include <stdlib.h>

static bool grow_capacity(size_t current, size_t *next) {
    if (next == NULL || current > SIZE_MAX / 2U) {
        return false;
    }
    *next = current == 0U ? 1U : current * 2U;
    return true;
}

bool vector_init(IntVector *vector, size_t initial_capacity) {
    if (vector == NULL) return false;
    vector->data = NULL;
    vector->size = 0U;
    vector->capacity = 0U;
    if (initial_capacity == 0U) return true;
    if (initial_capacity > SIZE_MAX / sizeof(int)) return false;
    vector->data = malloc(initial_capacity * sizeof(int));
    if (vector->data == NULL) return false;
    vector->capacity = initial_capacity;
    return true;
}

void vector_destroy(IntVector *vector) {
    if (vector == NULL) return;
    free(vector->data);
    vector->data = NULL;
    vector->size = 0U;
    vector->capacity = 0U;
}

bool vector_push(IntVector *vector, int value) {
    if (vector == NULL) return false;
    if (vector->size == vector->capacity) {
        size_t new_capacity;
        if (!grow_capacity(vector->capacity, &new_capacity) ||
            new_capacity > SIZE_MAX / sizeof(int)) return false;
        int *new_data = realloc(vector->data, new_capacity * sizeof(int));
        if (new_data == NULL) return false;
        vector->data = new_data;
        vector->capacity = new_capacity;
    }
    vector->data[vector->size++] = value;
    return true;
}

bool vector_pop(IntVector *vector, int *value) {
    if (vector == NULL || value == NULL || vector->size == 0U) return false;
    *value = vector->data[--vector->size];
    return true;
}

bool vector_get(const IntVector *vector, size_t index, int *value) {
    if (vector == NULL || value == NULL || index >= vector->size) return false;
    *value = vector->data[index];
    return true;
}

void list_init(IntList *list) {
    if (list == NULL) return;
    list->head = NULL;
    list->size = 0U;
}

bool list_push_front(IntList *list, int value) {
    if (list == NULL) return false;
    ListNode *node = malloc(sizeof(*node));
    if (node == NULL) return false;
    node->value = value;
    node->next = list->head;
    list->head = node;
    list->size++;
    return true;
}

bool list_push_back(IntList *list, int value) {
    if (list == NULL) return false;
    ListNode *node = malloc(sizeof(*node));
    if (node == NULL) return false;
    node->value = value;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    } else {
        ListNode *current = list->head;
        while (current->next != NULL) current = current->next;
        current->next = node;
    }
    list->size++;
    return true;
}

bool list_pop_front(IntList *list, int *value) {
    if (list == NULL || value == NULL || list->head == NULL) return false;
    ListNode *node = list->head;
    *value = node->value;
    list->head = node->next;
    free(node);
    list->size--;
    return true;
}

bool list_find(const IntList *list, int value) {
    if (list == NULL) return false;
    for (const ListNode *node = list->head; node != NULL; node = node->next) {
        if (node->value == value) return true;
    }
    return false;
}

void list_destroy(IntList *list) {
    if (list == NULL) return;
    ListNode *node = list->head;
    while (node != NULL) {
        ListNode *next = node->next;
        free(node);
        node = next;
    }
    list->head = NULL;
    list->size = 0U;
}

bool stack_init(IntStack *stack, size_t initial_capacity) { return vector_init(stack, initial_capacity); }
void stack_destroy(IntStack *stack) { vector_destroy(stack); }
bool stack_push(IntStack *stack, int value) { return vector_push(stack, value); }
bool stack_pop(IntStack *stack, int *value) { return vector_pop(stack, value); }
bool stack_peek(const IntStack *stack, int *value) {
    if (stack == NULL || value == NULL || stack->size == 0U) return false;
    return vector_get(stack, stack->size - 1U, value);
}

void queue_init(IntQueue *queue) {
    if (queue == NULL) return;
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0U;
}

bool queue_enqueue(IntQueue *queue, int value) {
    if (queue == NULL) return false;
    ListNode *node = malloc(sizeof(*node));
    if (node == NULL) return false;
    node->value = value;
    node->next = NULL;
    if (queue->back == NULL) {
        queue->front = queue->back = node;
    } else {
        queue->back->next = node;
        queue->back = node;
    }
    queue->size++;
    return true;
}

bool queue_dequeue(IntQueue *queue, int *value) {
    if (queue == NULL || value == NULL || queue->front == NULL) return false;
    ListNode *node = queue->front;
    *value = node->value;
    queue->front = node->next;
    if (queue->front == NULL) queue->back = NULL;
    free(node);
    queue->size--;
    return true;
}

bool queue_peek(const IntQueue *queue, int *value) {
    if (queue == NULL || value == NULL || queue->front == NULL) return false;
    *value = queue->front->value;
    return true;
}

void queue_destroy(IntQueue *queue) {
    if (queue == NULL) return;
    ListNode *node = queue->front;
    while (node != NULL) {
        ListNode *next = node->next;
        free(node);
        node = next;
    }
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0U;
}
