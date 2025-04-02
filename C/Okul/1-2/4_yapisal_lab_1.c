#include <stdio.h>

#define MAXROW 10
#define MAXCOL 10

int main(){
    int M, N, i, j, sonuc, x, y;
    int matrix1[MAXROW][MAXCOL];
    int matrix2[MAXROW][MAXCOL];
    int *ptr1 = &matrix1[0][0];
    int *ptr2 = &matrix2[0][0];
    int kontrol1 = 1;
    int kontrol2 = 1;


    printf("1. matrisin sutun sayisini giriniz: ");
    scanf("%d", &N);
    printf("2. matrisin sutun sayisini giriniz: ");
    scanf("%d", &M);

    for(i=0;i<2;i++){
        for(j=0;j<N;j++){
            printf("1. dizi eleman[%d][%d]: ", i, j);
            scanf("%d", ptr1+i * MAXCOL+j);
        }
    }

    for(i=0;i<2;i++){
        for(j=0;j<M;j++){
            printf("2. dizi eleman[%d][%d]: ", i, j);
            scanf("%d", ptr2+i * MAXCOL+j);
        }
    }

    for(j=0;j<N-1;j++){
        if(*(ptr1+0 * MAXCOL+j) != *(ptr1+0 * MAXCOL+j+1))
            kontrol1 = 0;
    }

    for(j=0;j<M-1;j++){
        if(*(ptr2+0 * MAXCOL+j) != *(ptr2+0 * MAXCOL+j+1))
            kontrol2 = 0;
    }

    if(kontrol1 == 1){
        printf("1. matrix uygun degil. Tekrar girirniz.");
        for(i=0;i<2;i++){
            for(j=0;j<N;j++){
                printf("1. dizi eleman[%d][%d]: ", i, j);
                scanf("%d", (ptr1+i * MAXCOL+j));
            }
        } 
    }

    if(kontrol2 == 1){
        printf("2. matrix uygun degil. Tekrar girirniz.");
        for(i=0;i<2;i++){
            for(j=0;j<M;j++){
                printf("2. dizi eleman[%d][%d]: ", i, j);
                scanf("%d", (ptr2+i * MAXCOL+j));
            }
        }
    }

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(*(ptr1+0 * MAXCOL+i) == *(ptr2+0 * MAXCOL+j))
                sonuc = *(ptr1+1 * MAXCOL+i) + *(ptr2+1 * MAXCOL+j);
                x = i;
                y = j;
        }
    }

    printf("%d -> %d + %d = %d", *(ptr1+0 * MAXCOL+i), *(ptr1+1 * MAXCOL+i), *(ptr2+1 * MAXCOL+j), sonuc);
    
    
    return 0;
}