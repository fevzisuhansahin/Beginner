#include<stdio.h>

int switch_case_1();
int switch_case_2();

int main(){
    
    // switch_case_1();
    // switch_case_2();

    return 0;
 }

int switch_case_1(){

    int number=0; 

    printf("enter a number:");
    scanf("%d",&number);

    switch(number){

        case 10:
        printf("number is equals to 10");
        break;

        case 50:
        printf("number is equal to 50");
        break;

        case 100:
        printf("number is equal to 100");
        break;

        default:
        printf("number is not equal to 10, 50 or 100");

    }

}

int switch_case_2(){

    int x = 10, y = 5;
    int i = (x>y && x+y>0);

    switch(i){

        case 1:
        printf("hi");
        break;

        case 0:
        printf("bye");
        break;

        default:
        printf("Hello bye");

    }
    
}