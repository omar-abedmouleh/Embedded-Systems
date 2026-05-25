#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef union
{
    struct
    {
        unsigned char pin_0 : 1;
        unsigned char pin_1 : 1;
        unsigned char pin_2 : 1;
        unsigned char pin_3 : 1;
        unsigned char pin_4 : 1;
        unsigned char pin_5 : 1;
        unsigned char pin_6 : 1;
        unsigned char pin_7 : 1;
    } pins;

    unsigned char ports_all;

} pins_of_ports;

typedef struct 
{
    unsigned char name[20];
    unsigned int age;
}student_0;

struct student_1 
{
    unsigned char name[20];
    unsigned int age;
};

struct student_further_infos
{
    unsigned char father_name[20];
    unsigned char mother_name[20];
};



typedef struct student
{
    struct student *student_ptr;
    unsigned char name[20];
    unsigned int age;
    struct student_further_infos *further_infos_ptr; 
} student_2;

student_0 omar;
struct student_1 fahmi;

student_2 student_array[2];
struct student_further_infos further_infos_array[2];



void get_student_2_infos(student_2 student_array_func[], unsigned int number_of_students); 
void print_student_2_infos(student_2 student_array_func[], unsigned int number_of_students); 






int main(){
pins_of_ports port;

port.ports_all = 0x00;

port.pins.pin_0 = 1;
port.pins.pin_3 = 1;

printf("port = 0x%X\n", port.ports_all);
printf("**************** simple struct ******************\n");
strcpy(omar.name, "omar-abedmouleh");
strcpy(fahmi.name, "fahmi-boussif");
printf("Name of omar: %s\n",omar.name);
printf("Name of Fahmi: %s\n",fahmi.name);
printf("************************************************\n");

student_array[0].further_infos_ptr = &further_infos_array[0];
student_array[1].further_infos_ptr = &further_infos_array[1];
get_student_2_infos(student_array, 2);
print_student_2_infos(student_array, 2);



    return 0;
}












void get_student_2_infos(student_2 student_array_func[], unsigned int number_of_students){

    for (unsigned int i = 0; i<number_of_students;i++){
        printf("please enter name of student[%i]\n",i);
        gets(student_array_func[i].name);
        printf("please enter age of student [%i]\n",i);
        scanf("%i", &(student_array_func[i].age));
        printf("please enter name of the father of student [%i]\n",i);
        getchar();  // removes the '\n' after entering age
        gets((student_array_func[i].further_infos_ptr->father_name));
        printf("please enter name of the mother of student [%i]\n",i);
        gets((student_array_func[i].further_infos_ptr->mother_name));
        //fflush(stdin);

    }
}
void print_student_2_infos(student_2 student_array_func[], unsigned int number_of_students){

    for (unsigned int i = 0; i<number_of_students;i++){
        printf("name of student[%i] is %s\n",i, student_array_func[i].name);
       
        printf("age of student [%i] is %i\n",i,student_array_func[i].age );
        
        printf("name of the father of student [%i] is %s\n",i, student_array_func[i].further_infos_ptr->father_name);
       
        printf("name of the Mother of student [%i] is %s\n",i, student_array_func[i].further_infos_ptr->mother_name); 
        

    }
}

