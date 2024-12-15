#include <stdio.h>

int x;
int y;
int carpim;

int main(){

    printf("x ve y degerlerini giriniz: ");
    scanf("%d %d", &x, &y);
    carpim = x*y;
    if(carpim < 0){
        if(x < 0){
            printf("(%d,%d) 2. Bolgede \n", x, y);
        }
        else{
            printf("(%d,%d) 4. Bolgede \n", x, y);
        }
    }
    else if(carpim == 0){
        if(x == 0 && y != 0){
            printf("(%d,%d) y dogrusunun ustundedir \n", x, y);
        }
        else if(x != 0 && y == 0){
            printf("(%d,%d) x dogrusunun ustundedir \n", x, y);
        }
        else if(x == 0 && y == 0){
            printf("(%d,%d) orijindedir \n", x, y);
        }
    }
    else{
        if(x < 0){
            printf("(%d,%d) 3. Bolgede \n", x, y);
        }
        else{
            printf("(%d,%d) 1. Bolgede \n", x, y);
        }
    }

    return 0;
}