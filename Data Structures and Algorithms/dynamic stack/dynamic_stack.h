#ifndef STACK_ARRAY_DS_H
#define STACK_ARRAY_DS_H

#include <stdlib.h>
#include "Platform_Types.h"

typedef struct
{
    void **StackArray;    /* Points to the array that allocated in the heap */
    sint32 ElementCount;  /* Has the actual number of elements in the stack */
    uint32 StackMaxSize;  /* Has the maximum number of elements in the stack */
    sint32 stack_ptr;     /* Has the index of the top element in the stack */
} Stack_t;

typedef enum
{
    STACK_NOK = 0,        /* Stack operation not performed successfully */
    STACK_OK,             /* Stack operation performed successfully */
    STACK_FULL,           /* Stack is full */
    STACK_EMPTY,          /* Stack is empty */
    STACK_NULL_POINTER    /* NULL pointer passed to the Stack operations */
} StackStatus_t;

/**
  * @brief  This algorithm creates an empty stack by allocating the stack
  *         structure and the array from dynamic memory.
  * @param  maxSize Stack maximum number of elements
  * @param  ret_status Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
  */
Stack_t* CreateStack(uint32 maxSize, StackStatus_t *ret_status);

/**
  * @brief  This algorithm destroys the stack by freeing the allocated memory.
  * @param  stack_obj Pointer to the stack object
  * @param  ret_status Status returned while performing this operation
  * @retval NULL after destroying the stack
  */
Stack_t* DestroyStack(Stack_t *stack_obj, StackStatus_t *ret_status);

/**
  * @brief  This algorithm pushes an item into the stack.
  * @param  stack_obj Pointer to the stack object
  * @param  itemPtr Pointer to the item
  * @retval Status of the operation
  */
StackStatus_t PushStack(Stack_t *stack_obj, void *itemPtr);

/**
  * @brief  This algorithm pops the top item from the stack.
  * @param  stack_obj Pointer to the stack object
  * @param  ret_status Status returned while performing this operation
  * @retval Pointer to the popped item
  */
void* PopStack(Stack_t *stack_obj, StackStatus_t *ret_status);

/**
  * @brief  This algorithm returns the top item without removing it.
  * @param  stack_obj Pointer to the stack object
  * @param  ret_status Status returned while performing this operation
  * @retval Pointer to the top item
  */
void* StackTop(Stack_t *stack_obj, StackStatus_t *ret_status);

/**
  * @brief  This algorithm checks if the stack is full.
  * @param  stack_obj Pointer to the stack object
  * @retval Stack status
  */
StackStatus_t StackIsFull(Stack_t *stack_obj);

/**
  * @brief  This algorithm checks if the stack is empty.
  * @param  stack_obj Pointer to the stack object
  * @retval Stack status
  */
StackStatus_t StackIsEmpty(Stack_t *stack_obj);

/**
  * @brief  This algorithm returns the number of elements in the stack.
  * @param  stack_obj Pointer to the stack object
  * @param  ret_status Status returned while performing this operation
  * @retval Number of elements
  */
sint32 StackCount(Stack_t *stack_obj, StackStatus_t *ret_status);

#endif