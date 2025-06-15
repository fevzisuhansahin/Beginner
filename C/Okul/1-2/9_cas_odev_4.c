#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct kargo{
    int hedef;
}KARGO;

typedef struct sube{
    int id;
    KARGO teslim[MAX];
    int adet;
}SUBE;

int main(){

    srand(time(NULL));

    int i,j,adet,dogru = 0;
    char dizi[3] = {"Kadikoy","Besiktas","Bakirkoy"};
    int kargolar[]={2,0,1,2,2,1,0,1,0,2};
    int adetler[MAX];
    KARGO rastgele[MAX];
    SUBE subeler[3];

    for(i=0;i<3;i++){
        subeler[i].id = i;
        subeler[i].adet = 0;
    }

    for(i=0;i<10;i++){
        rastgele[i].hedef = rand() % 3;
        subeler[rastgele[i].hedef].teslim[subeler[rastgele[i].hedef].adet] = rastgele[i];
        subeler[rastgele[i].hedef].adet ++;
        if(rastgele[i].hedef == kargolar[i]) dogru++;
    }

    printf("VERILEN BILGILER\n");
    for(i=0;i<10;i++){
        printf("%d->%d  ", (i+1), kargolar[i]);
    }
    printf("\n----------------------------------\n");
    printf("RANDOM BILGILER\n");
    for(i=0;i<10;i++){
        printf("%d->%d  ", (i+1), rastgele[i].hedef);
    }
    printf("\n----------------------------------");
    printf("\nDogru sayisi:%d",dogru);
    
    return 0;
}