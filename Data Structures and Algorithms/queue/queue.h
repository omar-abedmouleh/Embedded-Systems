#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "platform_types.h"

typedef struct
{
    void **array_of_pointers;
    unsigned int element_cnt;
    unsigned int MAX_ELEMENT;
    signed int front;
    signed int rear;
} queue_t;

typedef enum
{
    func_ok = 0,
    func_not_ok,
    pointer_null,
    queue_full,
    queue_empty
} status_t;

queue_t *create_queue(unsigned int max_size, status_t *ptr_status);

status_t enqueue_fun(queue_t *queue, void *value);
void *dequeue_fun(queue_t *queue, status_t *status);

void *show_rear(queue_t *queue, status_t *status);
void *show_front(queue_t *queue, status_t *status);

#endif