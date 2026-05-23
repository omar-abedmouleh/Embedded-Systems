#include <stdio.h>

unsigned int array[5] = {0x44332211, 0x88667755, 0x12111009, 0x16151413,
                         0x20191817};

unsigned char array_1[5] = {'o', 'm', 'a', 'r'};

unsigned int array_2[5] = {0x44332211, 0x88667755, 0x12111009, 0x16151413,
                           0x20191817};

unsigned char string_0[9] = "aabbaaaa";

unsigned int *ptr_0 = NULL;
unsigned char *ptr_char = array_1;

/* Pointer to constant unsigned int:
   - You cannot change the value through this pointer.
   - You can change the pointer address itself. */
const unsigned int *ptr_1 = array;
/* Example:
   *ptr_1 = 99;      // Error
   ptr_1 = array_2;  // OK
*/

/* Same as const unsigned int *ptr_1:
   - You cannot change the value through this pointer.
   - You can change the pointer address itself. */
unsigned int const *ptr_2 = array;
/* Example:
   *ptr_2 = 99;      // Error
   ptr_2 = array_2;  // OK
*/

/* Constant pointer to unsigned int:
   - You cannot change the pointer address.
   - You can change the value through this pointer. */
unsigned int *const ptr_3 = array;
/* Example:
   ptr_3 = array_2 or ptr_3++ ++ptr_3;  // Error
   *ptr_3 = 99;      // OK
*/

/* Constant pointer to constant unsigned int:
   - You cannot change the pointer address.
   - You cannot change the value through this pointer.
   - It is read-only through this pointer. */
const unsigned int *const ptr_4 = array;
/* Example:
   ptr_4 = array_2;  // Error
   *ptr_4 = 99;      // Error
*/

void *ptr_5 = array;

int sum_of_adjacent_char(unsigned char *string_ptr, unsigned int length);

int main(void) {
  ptr_1 = array_2;

  ptr_0 = array;

  unsigned int sum_adjacent = 0;

  /* length = size of string_0 in bytes */
  sum_adjacent = sum_of_adjacent_char(string_0, sizeof(string_0));

  printf("sum of adjacent is %u\n", sum_adjacent);
  printf("=============================================\n");

  unsigned int value = 0;

  /*
     value = *ptr_0++;

     This is the same as:
     value = *(ptr_0++);

     Steps:
     1) value = *ptr_0
     2) ptr_0 = ptr_0 + 1
  */
  value = *ptr_0++;

  printf("address of ptr_0 = %p\n", (void *)ptr_0);
  printf("value of ptr_0   = 0x%X\n", *ptr_0);
  printf("value            = 0x%X\n", value);

  printf("=============================================\n");

  unsigned char value_1 = 0;

  /*
     value_1 = *++ptr_char;

     This is the same as:
     value_1 = *(++ptr_char);

     Steps:
     1) ptr_char = ptr_char + 1
     2) value_1 = *ptr_char
  */
  value_1 = *++ptr_char;

  printf("address of ptr_char = %p\n", (void *)ptr_char);
  printf("value of ptr_char   = %c\n", *ptr_char);
  printf("value of value_1    = %c\n", value_1);

  printf("=============================================\n");

  return 0;
}

int sum_of_adjacent_char(unsigned char *string_ptr, unsigned int length) {
  if (string_ptr == NULL) {
    printf("Error: string_ptr is NULL\n");
    return 0;
  }

  unsigned int counter = 0;
  unsigned int sum_adjacent = 0;

  while (counter < length - 1) {
    if (*string_ptr == *(string_ptr + 1)) {
      sum_adjacent += 1;
    }

    string_ptr++;

    printf("%u\n", counter);

    counter++;
  }

  return sum_adjacent;
}