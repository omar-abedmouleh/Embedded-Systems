#include "queue.h"
#include <stdlib.h>


queue_t *create_queue(unsigned int max_size, status_t *ptr_status)
{
    queue_t *queue = NULL;

    if (ptr_status == NULL)
    {
        return NULL;
    }

    if (max_size == 0)
    {
        *ptr_status = func_not_ok;
        return NULL;
    }

    queue = (queue_t *)malloc(sizeof(queue_t));

    if (queue == NULL)
    {
        *ptr_status = pointer_null;
        return NULL;
    }

    queue->array_of_pointers = (void **)calloc(max_size, sizeof(void *));

    if (queue->array_of_pointers == NULL)
    {
        *ptr_status = pointer_null;
        free(queue);
        queue = NULL;
        return NULL;
    }

    *ptr_status = func_ok;
    queue->element_cnt = 0;
    queue->front = -1;
    queue->rear = -1;
    queue->MAX_ELEMENT = max_size;

    return queue;
}
/*-----------------status-----------------
status_t *full_queue(queue_t *queue){
    status_t status=func_not_ok ;
    if (queue==NULL)
    {
        *status=pointer_null;
    }
    else{
        if (queue->MAX_ELEMENT==queue->element_cnt)
        {
            *status=queue_full;
        }
        

    }
    return status;
}

status_t *empty_queue(queue_t *queue){
        status_t *status=NULL;
    if (queue==NULL)
    {
        status=pointer_null;
    }
    else{
        if (queue->element_cnt==0)
        {
            status=queue_empty;
        }
        

    }
    return status;

}

*/
status_t enqueue_fun(queue_t *queue, void * value){

     status_t status=func_not_ok;
    if (queue == NULL || value== NULL)
    {
        status=pointer_null;
        
    }
    else{ if (queue->element_cnt==queue->MAX_ELEMENT)
    {
        status=queue_full;
    }
    else

    { 
        status=func_ok;
        queue->rear++;
        if (queue->rear==queue->MAX_ELEMENT)
        {
            queue->rear=0;
            
        }
        else{}
        queue->array_of_pointers[queue->rear]=value;

        if (queue->element_cnt==0){
            queue->front=0;
            queue->element_cnt=1;

        }
        else{
            queue->element_cnt++;
            
        }
    }
        

    }
    return status;
    
}
void *dequeue_fun(queue_t *queue, status_t *status)
{
    void *ptr = NULL;

    if (queue == NULL || status == NULL)
    {
        if (status != NULL)
        {
            *status = pointer_null;
        }
    }
    else
    {
        if (queue->element_cnt == 0)
        {
            *status = queue_empty;
        }
        else
        {
            *status = func_ok;

            ptr = queue->array_of_pointers[queue->front];

            queue->front++;

            if (queue->front == queue->MAX_ELEMENT)
            {
                queue->front = 0;
            }
            else
            {
                /* Nothing */
            }

            if (queue->element_cnt == 1)
            {
                queue->front = -1;
                queue->rear = -1;
                queue->element_cnt = 0;
            }
            else
            {
                queue->element_cnt--;
            }
        }
    }

    return ptr;
}

void *show_rear(queue_t *queue, status_t *status)
{
    void *ptr = NULL;

    if (status == NULL)
    {
        /* Cannot write status */
    }
    else if (queue == NULL)
    {
        *status = pointer_null;
    }
    else if (queue->element_cnt == 0)
    {
        *status = queue_empty;
    }
    else
    {
        ptr = queue->array_of_pointers[queue->rear];
        *status = func_ok;
    }

    return ptr;
}

void *show_front(queue_t *queue, status_t *status)
{
    void *ptr = NULL;

    if (status == NULL)
    {
        /* Cannot write status */
    }
    else if (queue == NULL)
    {
        *status = pointer_null;
    }
    else if (queue->element_cnt == 0)
    {
        *status = queue_empty;
    }
    else
    {
        ptr = queue->array_of_pointers[queue->front];
        *status = func_ok;
    }

    return ptr;
}