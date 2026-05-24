#include<stdio.h>


unsigned char string_0 [11]="**********";
unsigned char string_1[5]="OMAR";
void *mymemset(void *start_address, unsigned char value, unsigned int byte_length);
void *copymem(void *dst_address, const void *src_address, unsigned int count);

int main(){

    /*
    mymemset(string_0, 'a', 10);
    printf("neue string is %s\n", string_0);
    */
   copymem(string_0,string_1 , 4 );
   printf("neue String_0:\t %s\n",string_0);


    return 0;
}
void *mymemset(void *start_address, const unsigned char value,  unsigned int byte_length){

unsigned char *start_address_intern=start_address;


if (start_address==NULL)
{
    printf("Error Pointer NULL\n");
}
else{

while (byte_length--)
{
    *start_address_intern=value;
    start_address_intern++;
}

}
return start_address_intern;
}
void *copymem(void *dst_address, const void *src_address, unsigned int count){

    unsigned char *dst_address_intern= dst_address;
    //unsigned char *src_address_intern_0=src_address;
    unsigned int i =0;

    if (dst_address_intern==NULL || src_address ==NULL){

        printf("Error pointer is NULL\n");
    }
    else{
        for(i =0 ; i <count ;i++){
            *dst_address_intern=*(unsigned char *)src_address;
            dst_address_intern++;
            src_address++;
        }


    }
return dst_address_intern;




}






