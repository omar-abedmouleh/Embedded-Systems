#include <stdio.h>

unsigned int array_0[3][2] = {{1, 2}, {3, 4}, {5, 6}};

unsigned int array_1[2] = {0x11, 0x22};
unsigned int array_2[2] = {0x33, 0x44};

// unsigned int *ptr_0 = array_0;
unsigned int *ptr_1 = array_1;

unsigned int *ptr_2[2] = {&array_1[0], &array_2[0]};
unsigned int *ptr_3[2] = {&array_0[0][0], &array_0[0][1]};

unsigned char find_index_inside_array(const unsigned int *array,
                                      const unsigned int element,
                                      const unsigned int array_length,
                                      unsigned int *index);

int main() {
  /*
     printf("====================1D Array=================================0\n");
     printf("Address first Value of array_1 0x%x \n",array_1);
     printf("Address first Value of array_1 0x%x \n",ptr_2[0]);
     printf("Address first Value of array_2 0x%x \n",array_2);
     printf("Address first Value of array_2 0x%x \n",ptr_2[1]);
     printf("first Value of array_1 0x%x \n",*ptr_2[0]);
     printf("first Value of array_2 0x%x \n",*ptr_2[1]);
     printf("Address first Value of array_1 0x%x \n",ptr_1);
     printf("Address second Value of array_1 0x%x \n",array_1+1);
     printf("Address second Value of array_1 0x%x \n",ptr_1+1);
     printf("first value  of the  array_1 0x%x \n",array_1[0]);
     printf("first value  of the  array_1 0x%x \n",*(ptr_1));
     printf("second value  of the  array_1 0x%x \n",array_1[0+1]);
     printf("second value  of the  array_1 0x%x \n",*(ptr_1+1));
     printf("=============================================================0\n");
     printf("====================2D Array=================================0\n");

     printf("Address first Value of array_0 0x%x \n",&array_0[0][0]);
     printf("Address second value of array_0 0x%x\n", &array_0[0][0] + 1);
     printf("Address second Value of array_0 0x%x \n",&(array_0[0][1]));
     printf("first Value of array_0 0x%x \n",*((array_0[0])+0));
     printf("second Value of array_0 0x%x \n",*((array_0[0])+1));
     printf("first Value of array_0 0x%x \n",*(*(array_0+0)+0));
     printf("second Value of array_0 0x%x \n",*(*(array_0)+1));
     printf("first Value of array_0 0x%x \n",*ptr_3[0]);
     printf("first Value of array_0 0x%x \n",*(ptr_3[0]+5));

 */
unsigned int index_0 = 0;
unsigned char is_found = 0;

is_found = find_index_inside_array(array_1, 0x22, 2, &index_0);

if (is_found) {
    printf("index inside array is %u\n", index_0);
} else {
    printf("element not found\n");
}

  return 0;
}
unsigned char find_index_inside_array(const unsigned int *array,
                                      const unsigned int element,
                                      const unsigned int array_length,
                                      unsigned int *index)
{
    unsigned char found = 0;
    unsigned int i = 0;

    if ((array == NULL) || (index == NULL)) {
        return 0;
    }

    for (i = 0; i < array_length; i++) {
        if (array[i] == element) {
            *index = i;
            found = 1;
            break;
        }
    }

    return found;
}