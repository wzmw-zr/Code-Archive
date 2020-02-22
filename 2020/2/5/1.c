/*************************************************************************
	> File Name: 1.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月05日 星期三 11时12分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct stack_entry {
    void *data;
    struct stack_entry *next;
};

struct stack {
    struct stack_entry *head;
    int capacity;
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t is_full;
    pthread_cond_t is_empty;
};

struct stack *new_stack(int capacity) {
    struct stack *my_stack = calloc(1, sizeof(struct stack));
    if (my_stack == NULL) {
        return NULL;
    }
    my_stack->head = NULL;
    my_stack->capacity = capacity;
    my_stack->count = 0;
    pthread_mutex_init(&my_stack->mutex, NULL);
    pthread_cond_init(&my_stack->is_full, NULL);
    pthread_cond_init(&my_stack->is_empty, NULL);
    return my_stack;
}

int push(struct stack *my_stack, void *data) {
    if (pthread_mutex_lock(&my_stack->mutex) != 0) {
        return -1;
    }
	while (my_stack->count == my_stack->capacity) {
        pthread_cond_wait(&my_stack->is_full, &my_stack->mutex);
    }
    struct stack_entry *new_entry = calloc(1, sizeof(struct stack_entry));
    if (new_entry == NULL) {
        return -1;
    }
    new_entry->data = data;
    new_entry->next = my_stack->head;
    my_stack->head = new_entry;
    my_stack->count += 1;
    pthread_cond_signal(&my_stack->is_empty);
    if (pthread_mutex_unlock(&my_stack->mutex) != 0) {
        return -1;
    }
    return 0;
}

void *pop(struct stack *my_stack) {
    if (pthread_mutex_lock(&my_stack->mutex) != 0) {
        return (void *) -1;
    }
	while (my_stack->count == 0) {
        pthread_cond_wait(&my_stack->is_empty, &my_stack->mutex);
    }
    struct stack_entry *top = my_stack->head;
    my_stack->head = top->next;
    void *data = top->data;
    free(top);
    my_stack->count -= 1;
    pthread_cond_signal(&my_stack->is_full);
    if (pthread_mutex_unlock(&my_stack->mutex) != 0) {
        return (void *) -1;
    }
    return data;
}

int main() {
    return 0;
}
