#include<stdio.h>

void print_string (unsigned int num_1, unsigned int num2);

void (*print_string_ptr) (unsigned int , unsigned int);

int main(){

print_string_ptr=print_string;
print_string_ptr(3,4);

    return 0;
}

void print_string (unsigned int num_1, unsigned int num_2){

printf("number_one= %i \t number_two %i", num_1, num_2);

}