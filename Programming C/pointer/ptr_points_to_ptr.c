#include <stdio.h>

unsigned int array[5] = {0x11, 0x12, 0x13, 0x14, 0x15};

char array_char[3][6] = {
    "Omar ",
    "ahmed",
    "Lukas"
};

/*
   ptr_0 is an array of 5 pointers.
   Each pointer points to one element of array.
*/
unsigned int *ptr_0[5] = {
    &array[0],
    &array[1],
    &array[2],
    &array[3],
    &array[4]
};

#include <stdio.h>

unsigned int numberOne = 0x11;

/*
   ptr_numberOne is a pointer to unsigned int.

   It stores the address of numberOne.

   Meaning:
       ptr_numberOne  = &numberOne
       *ptr_numberOne = numberOne
*/
unsigned int *ptr_numberOne = &numberOne;

/*
   ptr_ptr_numberOne is a pointer to pointer to unsigned int.

   It stores the address of ptr_numberOne.

   Meaning:
       ptr_ptr_numberOne   = &ptr_numberOne
       *ptr_ptr_numberOne  = ptr_numberOne
       **ptr_ptr_numberOne = numberOne
*/
unsigned int **ptr_ptr_numberOne = &ptr_numberOne;

int main(void) {

    /*
       &numberOne gives the address of numberOne.
    */
    printf("address of numberOne using &numberOne: 0x%X\n", &numberOne);

    /*
       ptr_numberOne stores the address of numberOne.

       Therefore:
           ptr_numberOne == &numberOne
    */
    printf("address of numberOne using ptr_numberOne: 0x%X\n", ptr_numberOne);

    /*
       ptr_ptr_numberOne stores the address of ptr_numberOne.

       *ptr_ptr_numberOne gives the value stored inside ptr_numberOne.

       Since ptr_numberOne stores &numberOne:
           *ptr_ptr_numberOne == ptr_numberOne == &numberOne
    */
    printf("address of numberOne using *ptr_ptr_numberOne: 0x%X\n",
           *ptr_ptr_numberOne);

    /*
       &ptr_numberOne gives the address of the pointer variable itself.

       This is NOT the address of numberOne.
       This is the address where ptr_numberOne is stored in memory.
    */
    printf("address of ptr_numberOne using &ptr_numberOne: 0x%X\n",
           &ptr_numberOne);

    /*
       ptr_ptr_numberOne stores the address of ptr_numberOne.

       Therefore:
           ptr_ptr_numberOne == &ptr_numberOne
    */
    printf("address of ptr_numberOne using ptr_ptr_numberOne: 0x%X\n",
           ptr_ptr_numberOne);

    /*
       **ptr_ptr_numberOne gives the value of numberOne.

       Step by step:
           ptr_ptr_numberOne    -> address of ptr_numberOne
           *ptr_ptr_numberOne   -> value stored in ptr_numberOne
                                -> address of numberOne
           **ptr_ptr_numberOne  -> value stored at address of numberOne
                                -> numberOne
    */
    printf("value of numberOne using **ptr_ptr_numberOne: 0x%X\n",
           **ptr_ptr_numberOne);


    /*
       ptr_0[0]  -> address of array[0]
       *ptr_0[0] -> value of array[0]
    */
    printf("value of array[0] = 0x%X\n", *ptr_0[0]);

    /*
       ptr_0 is the address of the first pointer.
       *ptr_0 is ptr_0[0], so it is &array[0].
       **ptr_0 is the value at &array[0], so it is array[0].
    */
    printf("value using **ptr_0 = 0x%X\n", **ptr_0);
   // printf("address number_one 0x%X:\n", *

    /*
       ptr_0[0]  -> address of array[0]
       *ptr_0[0] -> value of array[0]
    */
    printf("value of array[0] = 0x%X\n", *ptr_0[0]);

    /*
       ptr_0 is the address of the first pointer.
       *ptr_0 is ptr_0[0], so it is &array[0].
       **ptr_0 is the value at &array[0], so it is array[0].
    */
    printf("value using **ptr_0 = 0x%X\n", **ptr_0);

    /*
       Access other elements
    */
    printf("value of array[1] = 0x%X\n", *ptr_0[1]);
    printf("value of array[2] = 0x%X\n", *ptr_0[2]);
    printf("value of array[3] = 0x%X\n", *ptr_0[3]);
    printf("value of array[4] = 0x%X\n", *ptr_0[4]);

    /*
       Print strings from 2D char array
    */
    printf("first name  = %s\n", array_char[0]);
    printf("second name = %s\n", array_char[1]);
    printf("third name  = %s\n", array_char[2]);

    return 0;
}