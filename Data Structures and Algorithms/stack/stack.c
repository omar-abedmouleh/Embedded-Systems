#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/*----------- init -----------------------*/
void stack_init(stack_t *stack)
{
    if (stack == NULL)
    {
        printf("Stack is NULL\n");
    }
    else
    {
        stack->number_of_elements = STACK_MAX_ELEMENTS;
        stack->stack_ptr = -1;
    }
}

/*----------- push -----------------------*/
status_t push_function(stack_t *stack, unsigned int *value_to_push)
{
    status_t status_func = FUNC_ERROR;

    if (stack == NUL||L  value_to_push == NULL)
    {
        status_func = FUNC_ERROR;
    }
    else
    {
        if (stack_full(stack) == STACK_FULL)
        {
            printf("Error: Stack is full\n");
            status_func = STACK_FULL;
        }
        else
        {
            stack->stack_ptr++;
            stack->data[stack->stack_ptr] = *value_to_push;
            status_func = FUNC_OK;
        }
    }

    return status_func;
}

/*----------- pop -----------------------*/
status_t pop_function(stack_t *stack, unsigned int *pop_value)
{
    status_t status_func = FUNC_ERROR;

    if (stack == NULL || pop_value == NULL)
    {
        status_func = FUNC_ERROR;
    }
    else
    {
        if (stack_empty(stack) == STACK_EMPTY)
        {
            printf("Error: Stack is empty\n");
            status_func = STACK_EMPTY;
        }
        else
        {
            *pop_value = stack->data[stack->stack_ptr];
            stack->stack_ptr--;
            status_func = FUNC_OK;
        }
    }

    return status_func;
}

/*----------- return top -----------------------*/
status_t top_return_func(stack_t *stack, unsigned int *top_value)
{
    status_t status_func = FUNC_ERROR;

    if (stack == NULL || top_value == NULL)
    {
        status_func = FUNC_ERROR;
    }
    else
    {
        if (stack_empty(stack) == STACK_EMPTY)
        {
            printf("Error: Stack is empty\n");
            status_func = STACK_EMPTY;
        }
        else
        {
            *top_value = stack->data[stack->stack_ptr];
            status_func = FUNC_OK;
        }
    }

    return status_func;
}

/*----------- empty status -----------------------*/
status_t stack_empty(stack_t *stack)
{
    status_t status_func = FUNC_ERROR;

    if (stack == NULL)
    {
        status_func = FUNC_ERROR;
    }
    else
    {
        if (stack->stack_ptr == -1)
        {
            status_func = STACK_EMPTY;
        }
        else
        {
            status_func = FUNC_OK;
        }
    }

    return status_func;
}

/*----------- full status -----------------------*/
status_t stack_full(stack_t *stack)
{
    status_t status_func = FUNC_ERROR;

    if (stack == NULL)
    {
        status_func = FUNC_ERROR;
    }
    else
    {
        if (stack->stack_ptr == ((signed int)stack->number_of_elements - 1))
        {
            status_func = STACK_FULL;
        }
        else
        {
            status_func = FUNC_OK;
        }
    }

    return status_func;
}

/*----------- normal status -----------------------*/
status_t stack_normal(stack_t *stack)
{
    status_t status_func = FUNC_ERROR;

    if (stack == NULL)
    {
        status_func = FUNC_ERROR;
    }
    else
    {
        if ((stack_full(stack) != STACK_FULL) &&
            (stack_empty(stack) != STACK_EMPTY))
        {
            status_func = PUSH_POSSIBLE;
        }
        else
        {
            status_func = FUNC_OK;
        }
    }

    return status_func;
}