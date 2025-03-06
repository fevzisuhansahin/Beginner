#include <stdio.h>

int main(){

    // Size of data type (sizeof() operator)

    printf("%d\n",sizeof(short int));
    printf("%d\n",sizeof(int));
    printf("%d\n",sizeof(long int));
    printf("%d\n",sizeof(long long int));
    printf("%d\n",sizeof(float));
    printf("%d\n",sizeof(double));


    // Casting (bir kalıba sokmak)

    // implicit (gizli) casting (automatic)

    int x = 1;
    float y = 2.3;
    x = x + y;          // Automaticly 3.3 will turn to 3

    // explicit (aşikar) casting (non-automatic)

    char c = 'A';
    x = (int) c;    // value of x is 65

    // Printf()
    /* FORMAT CHARACTERS
    - %d or %i   for integer
    - %f         for float
    - %lf        for double
    - %c         for char
    - %u         for unsigned
    - %s         for string
    */

    printf("sayi: %1.3lf", 5678.4875);
    int b =15/2;
    printf("\n%d", b);
    printf("\n%lf", (15/2));    // it cant work
    printf("\n%03d", b);        // put two zeroes before value of b

    return 0;  
}