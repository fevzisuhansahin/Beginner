#include<stdio.h>

// Fonksiyon Prototipleri
void sort_arr(int arr[], int n);
void find_same(int arr1[], int arr2[], int t);
void dizi_al(int arr1[], int arr2[] , int t);
void reverse_string(char str[]);
void str_al(char str[]);

int main(){
    int arr[]={45,23,98,12,25};
    int n = sizeof(arr)/sizeof(arr[0]); // Dizinin eleman sayisini hesapla

    sort_arr(arr, n);

    int t = 10; // Dizilerin eleman sayisi
    int arr1[t], arr2[t]; // Karsilastirilacak iki dizi

    find_same(arr1, arr2, t);

    char str[11];   // Max 10 harf icerecek dizi

    reverse_string(str);
   
    return 0;
}

// Selection Sort
void sort_arr(int arr[], int n){

    int i, j, min_idx, temp;

    for(i=0;i<n-1;i++){ // Diziyi tara
        min_idx = i;    // Ilk elemani min ayarla

        for(j=i+1;j<n;j++){ // Geri kalan elemanlari tara
            if(arr[min_idx] > arr[j])   // min den daha kucuk varsa
                min_idx = j;

        }

        // Swap islemi
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    // Sirali dizi yazdirma
    printf("sirali dizi ->");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}

void find_same(int arr1[], int arr2[], int t){

    int i, j;
    int same = 0;   // Ortak eleman sayacı
    int visited[t]; // Tekrar eden elemanları belirlemek için

    for(i=0;i<t;i++){
        visited[i] = 0;
    }

    // Kullanıcıdan dizileri al
    dizi_al(arr1, arr2, t);

    // Ortak eleman kontrolu
    for(i=0;i<t;i++){
        for(j=0;j<t;j++){
            if((arr1[i] == arr2[j]) && (visited[j] == 0)){
                same += 1;
                visited[j] = 1;
                break;
            }
        }
    }

    printf("Ayni eleman sayisi: %d\n", same);
}

void dizi_al(int arr1[], int arr2[] , int t){
    int i;

    printf("\n1. dizinin elemanlarini giriniz:\n");
    for(i=0;i<t;i++){
        scanf("%d", &arr1[i]);
    }

    printf("2. dizinin elemanlarini giriniz:\n");
    for(i=0;i<t;i++){
        scanf("%d", &arr2[i]);
    }
}

void reverse_string(char str[]){
    int i=0, n=0;
    char temp;

    str_al(str);

    while(str[i] != '\0'){
        n++;
        i++;
    }

    // Swap islemi
    for(i=0;i<(n/2);i++){
        temp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }

    // Stringin tersini yazdirma
    printf("Stringin tersi -> ");
    for(i=0;i<n;i++){
        printf("%c", str[i]);
    }

    //Alternatif yazdirma secenekleri
    //printf("\nStringin tersi 2 -> %s\n", str);
    //puts(str);
}

void str_al(char str[]){
    printf("Ters cevirmek istediginiz kelimeyi giriniz: ");

    // scanf'ten sonra tamponu temizle
    while (getchar() != '\n');

    gets(str);
}