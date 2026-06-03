#include <stdio.h>
#include "stack.h"

int main(void)
{
    stack_t my_stack;
    unsigned int value = 0;
    unsigned int pop_value = 0;
    unsigned int top_value = 0;

    stack_init(&my_stack);

    value = 10;
    push_function(&my_stack, &value);

    value = 20;
    push_function(&my_stack, &value);

    value = 30;
    push_function(&my_stack, &value);

    top_return_func(&my_stack, &top_value);
    printf("Top value = %u\n", top_value);

    pop_function(&my_stack, &pop_value);
    printf("Pop value = %u\n", pop_value);

    pop_function(&my_stack, &pop_value);
    printf("Pop value = %u\n", pop_value);

    pop_function(&my_stack, &pop_value);
    printf("Pop value = %u\n", pop_value);

    return 0;
}