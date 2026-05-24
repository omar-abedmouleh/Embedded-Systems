#include <stdio.h>
#include <stdlib.h>
#include "function.h"

/* Function prototype */
void print_from_main(void);

int main(void) {
    print_notofication(print_from_main);

    return 0;
}

void print_from_main(void) {
    printf("I'm a Car\n");
}