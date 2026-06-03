#include <stdio.h>
#include "dynamic_stack.h"

int main(void)
{
    StackStatus_t status;
    Stack_t *myStack = NULL;

    int x = 10;
    int y = 20;
    int z = 30;

    myStack = CreateStack(5, &status);

    if (STACK_OK != status)
    {
        printf("Stack creation failed\n");
        return 1;
    }

    PushStack(myStack, &x);
    PushStack(myStack, &y);
    PushStack(myStack, &z);

    int *topValue = (int *)StackTop(myStack, &status);
    if (STACK_OK == status)
    {
        printf("Top value = %d\n", *topValue);
    }

    int *popValue = (int *)PopStack(myStack, &status);
    if (STACK_OK == status)
    {
        printf("Pop value = %d\n", *popValue);
    }

    printf("Stack count = %d\n", StackCount(myStack, &status));

    myStack = DestroyStack(myStack, &status);

    return 0;
}