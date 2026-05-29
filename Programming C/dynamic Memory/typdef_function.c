#include <stdio.h>

unsigned int print_s1(void);
unsigned int print_s2(void);
unsigned int print_s3(void);
unsigned int print_s4(void);

unsigned int array_0[2] = {10, 20};
unsigned int array_1[2] = {30, 40};

/* Array with two pointers to unsigned int */
unsigned int *ptr[2] = {NULL, NULL};

unsigned int numberOne = 5;
unsigned int *ptr_numberOne = &numberOne;
unsigned int **ptr_ptr_numberOne = &ptr_numberOne;

/*
   Function pointer type:
   points to a function with no parameters and unsigned int return value.
*/
typedef unsigned int (*function_ptr_t)(void);

/*
   Array type with 4 function pointers.
*/
typedef function_ptr_t function_array_t[4];

/*
   Function pointer that points to print_s1.
   Old form:
       unsigned int (*ptr_function)(void) = print_s1;
*/
function_ptr_t ptr_function = print_s1;

/*
   Array of 4 function pointers.
   Old form:
       unsigned int (*functions_array[4])(void);
*/
function_array_t functions_array = {
    print_s1,
    print_s2,
    print_s3,
    print_s4
};

/*
   Function that returns a pointer to an array of 4 function pointers.

   Old form:
       unsigned int (*(*array_of_function(void))[4])(void);

   New form with typedef:
       function_array_t *array_of_function(void);
*/
function_array_t *array_of_function(void);

int main(void)
{
    printf("===========================\n");

    ptr[0] = &array_0[0];
    ptr[1] = &array_1[0];

    printf("value of numberOne is %u\n", *ptr_numberOne);
    printf("value of numberOne is %u\n", **ptr_ptr_numberOne);

    printf("array_0[%i] = %u\n", 0, *ptr[0]);
    printf("array_1[%i] = %u\n", 0, *ptr[1]);

    printf("===========================\n");

    /* Call function through function pointer */
    printf("value returned is %u\n", ptr_function());

    printf("===========================\n");

    /*
       array_of_function() returns the address of functions_array.
       After dereferencing, we can access the function pointers by index.
    */
    printf("function 0 returns %u\n", (*array_of_function())[0]());
    printf("function 1 returns %u\n", (*array_of_function())[1]());
    printf("function 2 returns %u\n", (*array_of_function())[2]());
    printf("function 3 returns %u\n", (*array_of_function())[3]());

    printf("===========================\n");

    return 0;
}

/*
   Returns the address of the complete function pointer array.
*/
function_array_t *array_of_function(void)
{
    return &functions_array;
}

unsigned int print_s1(void)
{
    printf("s1\n");
    return 11;
}

unsigned int print_s2(void)
{
    printf("s2\n");
    return 22;
}

unsigned int print_s3(void)
{
    printf("s3\n");
    return 33;
}

unsigned int print_s4(void)
{
    printf("s4\n");
    return 44;
}