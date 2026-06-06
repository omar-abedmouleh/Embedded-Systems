#include "dynamic_stack.h"
#include <stdio.h>
#include <stdlib.h>

/*----------- Create Stack----------------------*/
Stack_t* CreateStack(uint32 maxSize, StackStatus_t *ret_status)
{
    Stack_t *my_Stack = NULL;

    if (NULL == ret_status)
    {
        return NULL;
    }
    else if (0 == maxSize)
    {
        *ret_status = STACK_NOK;
        return NULL;
    }
    else
    {
        my_Stack = (Stack_t *)malloc(sizeof(Stack_t));

        if (NULL == my_Stack)
        {
            *ret_status = STACK_NOK;
        }
        else
        {
            my_Stack->ElementCount = 0;
            my_Stack->StackMaxSize = maxSize;

            my_Stack->stack_ptr = -1;
            /*
            Pointer-to-pointer example:

            unsigned int a = 10;
            unsigned int *ptr = NULL;
            ptr = &a;

            unsigned int **ptr_ptr = NULL;
            ptr_ptr = &ptr;

            ptr_ptr
                gives the address of ptr

            *ptr_ptr
                gives the value stored in ptr,
                so it gives the address of a

            **ptr_ptr
                gives the value of a
            */

            /*
            StackArray is a pointer to pointer.

            my_Stack->StackArray is similar to ptr_ptr.
            It stores the address of the first element of a dynamic array of pointers.

            Each element in this array is a void*.
            That means each element can store the address of an item.

            my_Stack->StackArray[0]
                is the first element of the dynamic pointer array

            my_Stack->StackArray[0]
                is identical to *(my_Stack->StackArray + 0)

            *my_Stack->StackArray
                is identical to my_Stack->StackArray[0]
            */

            my_Stack->StackArray = (void **)calloc(my_Stack->StackMaxSize, sizeof(void *));

            if (NULL == my_Stack->StackArray)
            {
                free(my_Stack);
                my_Stack = NULL;
                *ret_status = STACK_NOK;
            }
            else
            {
                *ret_status = STACK_OK;
            }
        }
    }

    return my_Stack;
}

/*-------------- Destroy Stack-----*/
Stack_t* DestroyStack(Stack_t *stack_obj, StackStatus_t *ret_status)
{
    if (NULL == ret_status)
    {
        return stack_obj; /* Cannot update status because ret_status is NULL */
    }
    else if (NULL == stack_obj)
    {
        *ret_status = STACK_NULL_POINTER; /* Stack pointer is NULL */
        return NULL; /* No stack to destroy */
    }
    else
    {
        /*
        * StackArray points to memory allocated in the heap.
        * free() releases this memory.
        * After free(), the pointer may still hold the old invalid address.
        * Setting it to NULL prevents using a dangling pointer by mistake.
        */
        free(stack_obj->StackArray); /* Free the dynamic array inside the stack */
        stack_obj->StackArray = NULL; /* Avoid dangling pointer */

        free(stack_obj); /* Free the stack object itself */
        stack_obj = NULL; /* Clear local pointer */

        *ret_status = STACK_OK; /* Stack destroyed successfully */
    }

    return NULL; /* Return NULL to clear caller pointer */
}

/*--------------Push Stack---------------------------------*/
StackStatus_t PushStack(Stack_t *stack_obj, void *itemPtr)
{
    StackStatus_t StackStatus = STACK_NOK;

    if ((NULL == stack_obj) || (NULL == itemPtr))
    {
        StackStatus = STACK_NULL_POINTER;
    }
    else
    {
        if (STACK_FULL == StackIsFull(stack_obj))
        {
            printf("Error: Stack is full\n");
            StackStatus = STACK_FULL;
        }
        else
        {
            stack_obj->stack_ptr++;
            stack_obj->StackArray[stack_obj->stack_ptr] = itemPtr;
            stack_obj->ElementCount++;
            StackStatus = STACK_OK;
        }
    }

    return StackStatus;
}

/*-------------------- Pop Stack ------------------------------*/
void* PopStack(Stack_t *stack_obj, StackStatus_t *ret_status)
{
    void *value_to_return = NULL;

    if (NULL == ret_status)
    {
        return NULL;
    }
    else if (NULL == stack_obj)
    {
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        if (STACK_EMPTY == StackIsEmpty(stack_obj))
        {
            printf("Error: Stack is empty\n");
            *ret_status = STACK_EMPTY;
        }
        else
        {
            value_to_return = stack_obj->StackArray[stack_obj->stack_ptr];
            stack_obj->StackArray[stack_obj->stack_ptr] = NULL;
            stack_obj->stack_ptr--;
            stack_obj->ElementCount--;
            *ret_status = STACK_OK;
        }
    }

    return value_to_return;
}

/*-------------------- Stack Top ------------------------------*/
void* StackTop(Stack_t *stack_obj, StackStatus_t *ret_status)
{
    void *value_to_return = NULL;

    if (NULL == ret_status)
    {
        return NULL;
    }
    else if (NULL == stack_obj)
    {
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        if (STACK_EMPTY == StackIsEmpty(stack_obj))
        {
            printf("Error: Stack is empty\n");
            *ret_status = STACK_EMPTY;
        }
        else
        {
            value_to_return = stack_obj->StackArray[stack_obj->stack_ptr];
            *ret_status = STACK_OK;
        }
    }

    return value_to_return;
}

/*-------------------- Stack Is Full --------------------------*/
StackStatus_t StackIsFull(Stack_t *stack_obj)
{
    StackStatus_t StackStatus = STACK_NOK;

    if (NULL == stack_obj)
    {
        StackStatus = STACK_NULL_POINTER;
    }
    else
    {
        if (stack_obj->ElementCount == stack_obj->StackMaxSize)
        {
            StackStatus = STACK_FULL;
        }
        else
        {
            StackStatus = STACK_OK;
        }
    }

    return StackStatus;
}

/*-------------------- Stack Is Empty ------------*/
StackStatus_t StackIsEmpty(Stack_t *stack_obj)
{
    StackStatus_t StackStatus = STACK_NOK;

    if (NULL == stack_obj)
    {
        StackStatus = STACK_NULL_POINTER;
    }
    else
    {
        if (0 == stack_obj->ElementCount)
        {
            StackStatus = STACK_EMPTY;
        }
        else
        {
            StackStatus = STACK_OK;
        }
    }

    return StackStatus;
}

/*--------------------Stack Count-------------------------*/
sint32 StackCount(Stack_t *stack_obj, StackStatus_t *ret_status)
{
    sint32 count = -1;

    if (NULL == ret_status)
    {
        return -1;
    }
    else if (NULL == stack_obj)
    {
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        count = stack_obj->ElementCount;
        *ret_status = STACK_OK;
    }

    return count;
}