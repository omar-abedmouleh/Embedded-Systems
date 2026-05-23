#include<stdio.h>

unsigned int array_0[3][2]={{1,2},{3,4},{5,6}};

unsigned int array_1[2]={0x11,0x22};
unsigned int array_2[2]={0x33,0x44};

//unsigned int *ptr_0 = array_0;
unsigned int *ptr_1=array_1;

unsigned int *ptr_2[2]={&array_1[0],&array_2[0]};
unsigned int *ptr_3[2]={&array_0[0][0],&array_0[0][1]};



int main() {

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




    
    printf("=============================================================0\n");

    return 0;
}