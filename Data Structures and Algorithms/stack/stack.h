#ifndef STACK_H
#define STACK_H

#define STACK_MAX_ELEMENTS 5

typedef enum status
{
    FUNC_ERROR = 0,
    FUNC_OK,
    STACK_EMPTY,
    STACK_FULL,
    PUSH_POSSIBLE
} status_t;

typedef struct stack
{
    unsigned int data[STACK_MAX_ELEMENTS];
    unsigned int number_of_elements;
    signed int stack_ptr;
} stack_t;

void stack_init(stack_t *stack);

status_t push_function(stack_t *stack, unsigned int *value_to_push);
status_t pop_function(stack_t *stack, unsigned int *pop_value);
status_t top_return_func(stack_t *stack, unsigned int *top_value);

status_t stack_empty(stack_t *stack);
status_t stack_full(stack_t *stack);
status_t stack_normal(stack_t *stack);

#endif