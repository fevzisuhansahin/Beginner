#include <stdio.h>

int N, k, i;    // Degiskenleri tanımladım

int main(){

    // Kullanıcı girdileri
    printf("Ucak sayisini giriniz: ");
    scanf("%d", &N);

    printf("Ucaklarin minimum kac dakika ara ile kalkacagini giriniz: ");
    scanf("%d", &k);

    int numbers[N], times[N];   // Kullanıcıdan alınacak dizileri tanimladim

    for(i=0 ; i<N ; i++){       // Kullanicidan ucaklar hakkindaki bilgileri aldim
        printf("%d. ucagin numarasini giriniz: ", i+1);
        scanf("%d", &numbers[i]);
        printf("%d. ucagin talep edilen kalkis saatini giriniz: ", i+1);
        scanf("%d", &times[i]);
    }

    // Pistler
    int counter1 = 1, counter2 = 1; // Pistlerdeki uçak sayisini belli eden degiskenler
    int pist1n[N], pist1t[N], pist2n[N], pist2t[N]; //pistlerin dizilerini tanımladım
    float gecikmetop1 = 0, gecikmetop2 = 0;

    pist1n[0] = numbers[0];
    pist1t[0] = times[0];   // Pistlere ilk uçakları elimle yerleştirdim.
    pist2n[0] = numbers[1];
    pist2t[0] = times[1];   // Çünkü dakikalar küçükten büyüğe sıralı.

    for(i=2 ; i<N ; i++){

        int fark1 = times[i] - pist1t[counter1 - 1];    // Yeni yerlestirecegimiz ucakla 1. pistteki son ucagin arasindaki dakika farkı
        int fark2 = times[i] - pist2t[counter2 - 1];    // Yeni yerlestirecegimiz ucakla 2. pistteki son ucagin arasindaki dakika farkı

        if(fark1 > fark2){     // 1. piste yerleştirilecek

            int gecikme1 = k - fark1;
            if(fark1 < k){   // 
                pist1n[counter1] = numbers[i];
                pist1t[counter1] = times[i] + gecikme1;
                counter1++;
                gecikmetop1 = gecikmetop1 + gecikme1;
            }
            else{
                pist1n[counter1] = numbers[i];
                pist1t[counter1] = times[i];
                counter1++; 
            }
        }
        else if(fark1 == fark2){
            int gecikme1 = k - fark1;
            int gecikme2 = k - fark2;
            if(counter1 > counter2){
                if(fark2 < k){
                pist2n[counter2] = numbers[i];
                pist2t[counter2] = times[i] + gecikme2;
                counter2++;
                gecikmetop2 = gecikmetop2 + gecikme2;
                }
                else{
                    pist2n[counter2] = numbers[i];
                    pist2t[counter2] = times[i];
                    counter2++;
                }
            }
            else{
              if(fark1 < k){   // 
                pist1n[counter1] = numbers[i];
                pist1t[counter1] = times[i] + gecikme1;
                counter1++;
                gecikmetop1 = gecikmetop1 + gecikme1;
            }
                else{
                    pist1n[counter1] = numbers[i];
                    pist1t[counter1] = times[i];
                    counter1++; 
                }  
            }
        }

        else{

            int gecikme2 = k - fark2;
            if(fark2 < k){
                pist2n[counter2] = numbers[i];
                pist2t[counter2] = times[i] + gecikme2;
                counter2++;
                gecikmetop2 = gecikmetop2 + gecikme2;
            }
            else{
                pist2n[counter2] = numbers[i];
                pist2t[counter2] = times[i];
                counter2++;
            }
        }

    }

    printf("      Birinci Pist\n");
    printf("--------------------------\n");
    printf("Ucak Numarasi-Kalkis Saati\n");
    for(i=0 ; i<counter1 ; i++){

        printf("%d-", pist1n[i]);
        printf("%d\n", pist1t[i]);

    }
    printf("Ortalama Gecikme = %f\n", gecikmetop1/counter1);

    printf("      Ikinci Pist\n");
    printf("--------------------------\n");
    printf("Ucak Numarasi-Kalkis Saati\n");
    for(i=0 ; i<counter2 ; i++){

        printf("%d-", pist2n[i]);
        printf("%d\n", pist2t[i]);

    }
    printf("Ortalama Gecikme = %f\n", gecikmetop2/counter2);
    
    return 0;
}