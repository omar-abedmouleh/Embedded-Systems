#include <stdio.h>

unsigned int number_1;
unsigned int number_2;

void *ptr_1 = NULL;
void *ptr_2 = NULL;

unsigned int *ptr_4 = NULL;
unsigned int *ptr_5 = NULL;

void swap_function(unsigned int *num_1, unsigned int *num_2);

int main(void) {
    printf("enter first number\n");
    scanf("%u", &number_1);

    printf("enter second number\n");
    scanf("%u", &number_2);

    printf("Before swap: %u\t%u\n", number_1, number_2);

    ptr_4 = &number_1;
    ptr_5 = &number_2;

    swap_function(ptr_4, ptr_5);

    printf("After swap with unsigned int pointers: %u\t%u\n", number_1, number_2);

    ptr_1 = &number_1;
    ptr_2 = &number_2;

    swap_function((unsigned int *)ptr_1, (unsigned int *)ptr_2);

    printf("After swap with void pointers: %u\t%u\n", number_1, number_2);

    return 0;
}

void swap_function(unsigned int *num_1, unsigned int *num_2) {
    unsigned int temp = 0;

    temp = *num_1;
    *num_1 = *num_2;
    *num_2 = temp;
}