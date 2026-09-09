#include "data_structures.h"

#include <assert.h>
#include <stdio.h>

static void test_vector(void) {
    IntVector v;
    assert(vector_init(&v, 2));
    assert(vector_push(&v, 10));
    assert(vector_push(&v, 20));
    assert(vector_push(&v, 30));
    int value = 0;
    assert(vector_get(&v, 2, &value) && value == 30);
    assert(vector_pop(&v, &value) && value == 30);
    assert(!vector_get(&v, 10, &value));
    vector_destroy(&v);
}

static void test_list(void) {
    IntList list;
    list_init(&list);
    assert(list_push_front(&list, 20));
    assert(list_push_front(&list, 10));
    assert(list_push_back(&list, 30));
    assert(list.size == 3);
    assert(list_find(&list, 20));
    int value = 0;
    assert(list_pop_front(&list, &value) && value == 10);
    list_destroy(&list);
    assert(list.size == 0);
}

static void test_stack(void) {
    IntStack stack;
    assert(stack_init(&stack, 1));
    assert(stack_push(&stack, 1));
    assert(stack_push(&stack, 2));
    int value = 0;
    assert(stack_peek(&stack, &value) && value == 2);
    assert(stack_pop(&stack, &value) && value == 2);
    assert(stack_pop(&stack, &value) && value == 1);
    assert(!stack_pop(&stack, &value));
    stack_destroy(&stack);
}

static void test_queue(void) {
    IntQueue queue;
    queue_init(&queue);
    assert(queue_enqueue(&queue, 100));
    assert(queue_enqueue(&queue, 200));
    int value = 0;
    assert(queue_peek(&queue, &value) && value == 100);
    assert(queue_dequeue(&queue, &value) && value == 100);
    assert(queue_dequeue(&queue, &value) && value == 200);
    assert(!queue_dequeue(&queue, &value));
    queue_destroy(&queue);
}

int main(void) {
    test_vector(); test_list(); test_stack(); test_queue();
    puts("All data structure tests passed.");
    return 0;
}
