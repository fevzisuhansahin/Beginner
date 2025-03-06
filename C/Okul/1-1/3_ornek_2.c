#include <stdio.h>

long int S;
int toplam;

int main(){
    
    printf("Pozitif sayiyi giriniz: ");
    scanf("%d", &S);
    
    while(S <= 0){
        printf("Lutfen pozitif bir sayi giriniz: \n");
        scanf("%d", &S);
    }

    while(S>10){
        toplam = 0;
        while(S>0){
            toplam = toplam + S%10;
            S = S/10;
        }
        printf("Basamaklarin toplami: %d\n", toplam);
        S = toplam;
    }
    printf("Ulasilan tek basamakli sayi: %d\n", S);
    
    return 0;
}