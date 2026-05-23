#include <stdio.h>

/* Global array of unsigned integers */
unsigned int array[5] = {
    0x44332211,
    0x88667755,
    0x12111009,
    0x16151413,
    0x20191817
};

/*
   first_string is a pointer to a string literal.

   Important:
   - first_string points to the first character 'O'.
   - The string literal should be treated as read-only.
   - Changing the characters through first_string is not allowed.
*/
char *first_string = "Omar_27";

/*
   second_string is a character array.

   Important:
   - The content is stored inside the array.
   - The array has 8 bytes:
       'O' 'm' 'a' 'r' '_' '2' '7' '\0'
   - The content of this array can be changed.
*/
char second_string[8] = "Omar_27";

int main(void) {
    /*
       %s prints a string.

       first_string contains the address of the first character.
       printf starts printing from this address until it finds '\0'.
    */
    printf("value of first_string: %s\n", first_string);

    /*
       %p prints an address.

       first_string + 1 points to the second character of the string.
       first_string points to 'O'.
       first_string + 1 points to 'm'.
    */
    printf("address of second character in first_string: %p\n",
           (void *)(first_string + 1));

    /*
       This is not allowed because first_string points to a string literal.
       String literals should not be modified.

       first_string points to:
       'O' 'm' 'a' 'r' '_' '2' '7' '\0'

       The following line would be undefined behavior:
    */
    /* *(first_string) = 'W'; */

    /*
       This changes the pointer itself.

       Before:
           first_string points to 'O'

       After:
           first_string points to 'm'

       The string literal itself is not changed.
       Only the pointer is moved to the next character.
    */
    first_string++;

    /*
       *first_string gives the value at the address stored in first_string.

       After first_string++:
           first_string points to 'm'

       Therefore, *first_string is 'm'.
    */
    printf("value pointed to by first_string after increment: %c\n",
           *first_string);

    /*
       second_string is an array, not a string literal.

       Therefore, modifying its characters is allowed.
       This changes the first character from 'O' to 'W'.
    */
    second_string[0] = 'W';

    /*
       %s prints the content of second_string.

       After changing second_string[0] to 'W',
       the output becomes:
           Wmar_27
    */
    printf("value of second_string: %s\n", second_string);

    /*
       When an array name is used like this, it decays to a pointer
       to its first element.

       second_string is equivalent to:
           &second_string[0]

       Therefore, this prints the address of the first character.
    */
    printf("address of first character in second_string: %p\n",
           (void *)second_string);

    /*
       second_string + 1 points to the second character of the array.

       second_string points to:
           second_string[0]

       second_string + 1 points to:
           second_string[1]
    */
    printf("address of second character in second_string: %p\n",
           (void *)(second_string + 1));

    return 0;
}

/*
   %s  -> prints a string, needs char *
   %c  -> prints one character, needs char
   %p  -> prints an address, needs void *

   first_string      -> address of first character
   *first_string     -> value at this address

   second_string     -> address of first array element
   second_string[0]  -> first character
   *second_string    -> first character
*/