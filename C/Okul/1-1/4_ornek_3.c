#include <stdio.h>

int n, i, j, k, counter;

int main(){
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d", &n);

    int A[n], unique[n];

    for(i = 0;i<n;i++){
        printf("%d. elemani giriniz: ",(i+1));
        scanf("%d", &A[i]);
    }

    for(i=0;i<n;i++){
        int tekrar=0;

        for(j=0;j<counter;j++){
            tekrar=tekrar+(A[i]==unique[j]);
        }
        if(tekrar==0){
            unique[counter]=A[i];
            counter=counter+1;
        }
    }

    for(i=0,j=counter-1;i<j;i++,j--){
        int temp = unique[i];
        unique[i]=unique[j];
        unique[j]=temp;
    }

    printf("Benzersiz eleman dizisinin ters hali: \n");
    for(i=0;i<counter;i++){
        printf("%d", unique[i]);
    }

    return 0;
}