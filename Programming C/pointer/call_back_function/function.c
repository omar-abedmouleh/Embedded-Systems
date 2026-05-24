#include "function.h"

void print_notofication(void (*function_from_main)(void)) {
    printf("This is a Vehicle\n");

    function_from_main();
}