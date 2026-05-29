#include <stdio.h>
#include <stdlib.h>

unsigned int **ptr_2d = NULL;

int main(void)
{
    unsigned int rows = 4;
    unsigned int cols = 3;

    /*
       Allocate memory for 4 row pointers.
       ptr_2d[0], ptr_2d[1], ptr_2d[2], ptr_2d[3]
    */
    ptr_2d = (unsigned int **)malloc(rows * sizeof(unsigned int *));

    if (ptr_2d == NULL)
    {
        printf("Memory allocation for rows failed\n");
        return 1;
    }

    /*
       Allocate memory for each row.
       Each row contains 3 unsigned int values.
    */
    for (unsigned int i = 0; i < rows; i++)
    {
        ptr_2d[i] = (unsigned int *)malloc(cols * sizeof(unsigned int));

        if (ptr_2d[i] == NULL)
        {
            printf("Memory allocation for row %u failed\n", i);

            /*
               Free already allocated rows before leaving.
            */
            for (unsigned int j = 0; j < i; j++)
            {
                free(ptr_2d[j]);
            }

            free(ptr_2d);
            ptr_2d = NULL;

            return 1;
        }
    }

    /*
       Fill the 2D array.
    */
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            ptr_2d[i][j] = (i + 1) * 10 + j;
        }
    }

    /*
       Print the 2D array.
    */
    printf("2D dynamic array:\n");

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            printf("%u\t", ptr_2d[i][j]);
        }

        printf("\n");
    }

    /*
       Free each row first.
    */
    for (unsigned int i = 0; i < rows; i++)
    {
        free(ptr_2d[i]);
        ptr_2d[i] = NULL;
    }

    /*
       Then free the array of row pointers.
    */
    free(ptr_2d);
    ptr_2d = NULL;

    return 0;
}