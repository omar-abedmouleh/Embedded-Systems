#include <stdio.h>
#include <stdlib.h>

unsigned int NumberOne = 5;

void *ptr = NULL;
unsigned int **ptr_2d=NULL;

int main(void)
{
    /*
       malloc reserves memory on the heap.
       The memory is not initialized.
    */
    ptr_2d=(unsigned int **)malloc(4*sizeof(unsigned int *));

    ptr = malloc(sizeof(unsigned int));

    if (ptr == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    /*
       ptr is void*, so we cast it to unsigned int*
       before writing an unsigned int value.
    */
    *((unsigned int *)ptr) = NumberOne;

    printf("After malloc:\n");
    printf("Value in dynamic memory: %u\n", *((unsigned int *)ptr));
    printf("Address in ptr: %p\n", ptr);

    /*
       realloc changes the size of an allocated block.

       Here we resize the block from 1 unsigned int
       to 3 unsigned int values.
    */
    void *temp_ptr = realloc(ptr, 3 * sizeof(unsigned int));

    /*
       Use a temporary pointer with realloc.
       If realloc fails, ptr still points to the old valid memory.
    */
    if (temp_ptr == NULL)
    {
        printf("realloc failed\n");
        free(ptr);
        ptr = NULL;
        return 1;
    }

    ptr = temp_ptr;

    /*
       Now the block can be used like an array with 3 elements.
    */
    ((unsigned int *)ptr)[0] = 10;
    ((unsigned int *)ptr)[1] = 20;
    ((unsigned int *)ptr)[2] = 30;

    printf("\nAfter realloc to 3 elements:\n");
    printf("ptr[0] = %u\n", ((unsigned int *)ptr)[0]);
    printf("ptr[1] = %u\n", ((unsigned int *)ptr)[1]);
    printf("ptr[2] = %u\n", ((unsigned int *)ptr)[2]);
    printf("Address after realloc: %p\n", ptr);

    /*
       realloc can also make the block larger again.

       Here we resize from 3 unsigned int values
       to 5 unsigned int values.
    */
    temp_ptr = realloc(ptr, 5 * sizeof(unsigned int));

    if (temp_ptr == NULL)
    {
        printf("second realloc failed\n");
        free(ptr);
        ptr = NULL;
        return 1;
    }

    ptr = temp_ptr;

    /*
       The old values are kept:
           ptr[0], ptr[1], ptr[2]

       The new elements:
           ptr[3], ptr[4]

       are not automatically initialized.
       Therefore, we write values into them.
    */
    ((unsigned int *)ptr)[3] = 40;
    ((unsigned int *)ptr)[4] = 50;

    printf("\nAfter realloc to 5 elements:\n");
    for (unsigned int i = 0; i < 5; i++)
    {
        printf("ptr[%u] = %u\n", i, ((unsigned int *)ptr)[i]);
    }

    /*
       realloc can also shrink the block.

       Here we keep only the first 2 elements.
       Values after index 1 are no longer valid.
    */
    temp_ptr = realloc(ptr, 2 * sizeof(unsigned int));

    if (temp_ptr == NULL)
    {
        printf("third realloc failed\n");
        free(ptr);
        ptr = NULL;
        return 1;
    }

    ptr = temp_ptr;

    printf("\nAfter realloc to 2 elements:\n");
    printf("ptr[0] = %u\n", ((unsigned int *)ptr)[0]);
    printf("ptr[1] = %u\n", ((unsigned int *)ptr)[1]);

    /*
       free releases heap memory.
       After free, do not use ptr anymore.
    */
    free(ptr);
    ptr = NULL;

    /*
       calloc reserves memory and initializes it with zero.
    */
    ptr = calloc(3, sizeof(unsigned int));

    if (ptr == NULL)
    {
        printf("calloc failed\n");
        return 1;
    }

    printf("\nAfter calloc:\n");
    printf("ptr[0] = %u\n", ((unsigned int *)ptr)[0]);
    printf("ptr[1] = %u\n", ((unsigned int *)ptr)[1]);
    printf("ptr[2] = %u\n", ((unsigned int *)ptr)[2]);

    ((unsigned int *)ptr)[0] = 100;
    ((unsigned int *)ptr)[1] = 200;
    ((unsigned int *)ptr)[2] = 300;

    printf("\nAfter writing values into calloc memory:\n");
    for (unsigned int i = 0; i < 3; i++)
    {
        printf("ptr[%u] = %u\n", i, ((unsigned int *)ptr)[i]);
    }

    free(ptr);
    ptr = NULL;

    return 0;
}