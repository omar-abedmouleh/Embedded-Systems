#include "Application.h"

#include <stdio.h>

void print_my_name(void) { printf("my Name is Omar\n"); };

unsigned int returnVal = 0;

void Add_One(unsigned int *Pnumber1, unsigned int *Pnumber2)

{
  *Pnumber1 += 1;
  *Pnumber2 += 1;
};
unsigned int Get_Summing(unsigned int number_1, unsigned int number_2) {
  unsigned int Result = 0;
  Add_One(&number_1, &number_2);
  Result = number_1 + number_2;
  return Result;
};

int main() {
  printf("Hello, Embedded Systems!\n");

  print_my_name();
  printf("OMAR_TEST = %i \n", OMAR_TEST);
  if (returnVal == 0) {
    print_my_name();
  };

  unsigned int Data1 = 2;
  unsigned int Data2 = 3;
  unsigned int Result = 0;

  Result = Get_Summing(Data1, Data2);
  Result++;
  return 0;
}