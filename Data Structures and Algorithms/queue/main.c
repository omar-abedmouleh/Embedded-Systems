#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue_t *queue = NULL;

unsigned int a = 10;
unsigned int b = 20;
float c = 5.5f;
unsigned char string[6] = "omar";
char d = 'o';

int main(void)
{
    status_t status;
    void *ptr = NULL;

    queue = create_queue(5, &status);
    printf("create_queue status value is %i\n", status);

    printf("====================================\n");

    status = enqueue_fun(queue, &a);
    printf("enqueue a status value is %i\n", status);

    ptr = show_rear(queue, &status);
    printf("rear value after a is %u\n", *(unsigned int *)ptr);

    ptr = show_front(queue, &status);
    printf("front value after a is %u\n", *(unsigned int *)ptr);

    printf("====================================\n");

    status = enqueue_fun(queue, &b);
    printf("enqueue b status value is %i\n", status);

    ptr = show_rear(queue, &status);
    printf("rear value after b is %u\n", *(unsigned int *)ptr);

    ptr = show_front(queue, &status);
    printf("front value after b is %u\n", *(unsigned int *)ptr);

    printf("====================================\n");

    status = enqueue_fun(queue, &c);
    printf("enqueue c status value is %i\n", status);

    ptr = show_rear(queue, &status);
    printf("rear value after c is %.2f\n", *(float *)ptr);

    ptr = show_front(queue, &status);
    printf("front value after c is %u\n", *(unsigned int *)ptr);

    printf("====================================\n");

    status = enqueue_fun(queue, string);
    printf("enqueue string status value is %i\n", status);

    ptr = show_rear(queue, &status);
    printf("rear value after string is %s\n", (char *)ptr);

    ptr = show_front(queue, &status);
    printf("front value after string is %u\n", *(unsigned int *)ptr);

    printf("====================================\n");

    status = enqueue_fun(queue, &d);
    printf("enqueue d status value is %i\n", status);

    ptr = show_rear(queue, &status);
    printf("rear value after d is %c\n", *(char *)ptr);

    ptr = show_front(queue, &status);
    printf("front value after d is %u\n", *(unsigned int *)ptr);

    printf("====================================\n");
    printf("Start dequeue\n");
    printf("====================================\n");

    /*
       First dequeued element is a.
       Type: unsigned int
    */
    ptr = dequeue_fun(queue, &status);
    printf("dequeue status value is %i\n", status);
    printf("dequeued value a is %u\n", *(unsigned int *)ptr);

    /*
       Second dequeued element is b.
       Type: unsigned int
    */
    ptr = dequeue_fun(queue, &status);
    printf("dequeue status value is %i\n", status);
    printf("dequeued value b is %u\n", *(unsigned int *)ptr);

    /*
       Third dequeued element is c.
       Type: float
    */
    ptr = dequeue_fun(queue, &status);
    printf("dequeue status value is %i\n", status);
    printf("dequeued value c is %.2f\n", *(float *)ptr);

    /*
       Fourth dequeued element is string.
       Type: char array / string
    */
    ptr = dequeue_fun(queue, &status);
    printf("dequeue status value is %i\n", status);
    printf("dequeued value string is %s\n", (char *)ptr);

    /*
       Fifth dequeued element is d.
       Type: char
    */
    ptr = dequeue_fun(queue, &status);
    printf("dequeue status value is %i\n", status);
    printf("dequeued value d is %c\n", *(char *)ptr);

    printf("====================================\n");

    /*
       Try to dequeue again.
       Now the queue should be empty.
    */
    ptr = dequeue_fun(queue, &status);
    printf("dequeue from empty queue status value is %i\n", status);

    if (ptr == NULL)
    {
        printf("No value dequeued, queue is empty\n");
    }

    printf("====================================\n");

    return 0;
}