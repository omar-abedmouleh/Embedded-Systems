#include <stdio.h>

#include "first_code.h"


int main(void) {
  unsigned int value = 0;
  unsigned int value_macros = 0;
  unsigned int bit_index = 0;
  unsigned int operation_index = 0;

  printf("please enter the Value\n");
  scanf("%X", &value);

  printf("please enter the bit_index\n");
  scanf("%i", &bit_index);

  printf("please choose the Operation to do: Operation_index\n");
  printf("===================================\n");
  printf("operation_index\t\tMeaning\n");
  printf("0=\treset_bit\n");
  printf("1=\tset_bit\n");
  printf("2=\ttoggle_bit\n");
  scanf("%i", &operation_index);

  switch (operation_index) {
    case 0:
      printf("chosen Operation is reset\n");
      value = reset_bit_function(value, bit_index);
      break;
    case 1:
      printf("chosen Operation is Set\n");
      value = set_bit_function(value, bit_index);
      break;
    case 2:
      printf("chosen Operation is toggle\n");
      value = toggle_bit_function(value, bit_index);
      break;
    default:
      printf("unknown operation\n");
      break;
  }

  printf("value after Operation: %X\n", value);
  printf("===================================\n");
  printf("Operation with the Help of Macros\n");

  value_macros = value;
  value_macros = reset_bit(value_macros, bit_index);
  printf("Value after Operation with Macros: %X\n", value_macros);

  return 0;
}
