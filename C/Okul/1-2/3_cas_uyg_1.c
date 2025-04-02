#include<stdio.h>

void toplama(double a,double b);
void cikarma(double a,double b);
void carpma(double a,double b);
void bolme(double a,double b);
void us_alma(double a, int b);
void veri_alma(double *a, double*b, int us_mu);
void hesap_makinesi();

void sort_arr(int arr[], int n);
void find_same(int arr1[], int arr2[], int t);
void dizi_al(int arr1[], int arr2[] , int t);
void reverse_string(char str[]);
void str_al(char str[]);

int main(){
    // Uygulama sorusu 1
    hesap_makinesi();

    // Uygulama sorusu 2
    // a)
    int arr[]={45,23,98,12,25};
    int n = sizeof(arr)/sizeof(arr[0]); // Dizinin eleman sayisini hesapla
    sort_arr(arr, n);

    // b)
    int t = 10; // Dizilerin eleman sayisi
    int arr1[t], arr2[t]; // Karsilastirilacak iki dizi
    find_same(arr1, arr2, t);

    // c)
    char str[11];   // Max 10 harf icerecek dizi
    reverse_string(str);

    return 0;
}

void hesap_makinesi(){

    int islem;
    double a;
    double b;

    printf("---ISLEM LISTESI---\n1) Toplama\n2) Cikarma\n3) Carpma\n4) Bolme\n5) Us Alma\n");
    printf("Islem Numarasi Seciniz: ");
    scanf("%d", &islem);

    switch (islem){
    case 1:
        veri_alma(&a, &b, 0);
        toplama(a,b);
        break;
    case 2:
        veri_alma(&a, &b, 0);
        cikarma(a,b);
        break;
    case 3:
        veri_alma(&a, &b, 0);
        carpma(a,b);
        break;
    case 4:
        veri_alma(&a, &b, 0);
        bolme(a,b);
        break;
    case 5:
        veri_alma(&a, &b, 1);
        us_alma(a,b);
        break;
    default:
        printf("Gecersiz Islem\n");
        break;
    }
}

void toplama(double a,double b){
    double sonuc = 0;
    sonuc = a + b;
    printf("Toplam = %lf\n", sonuc);
}

void cikarma(double a,double b){
    double sonuc = 0;
    sonuc = a - b;
    printf("Fark = %lf\n", sonuc);
}

void carpma(double a,double b){
    double sonuc = 0;
    sonuc = a * b;
    printf("Carpim = %lf\n", sonuc);
}

void bolme(double a,double b){
    if(b==0){
        printf("Tanimsiz islem\n");
    }
    else{     
        double sonuc = 0;
        sonuc = a / b;
        printf("Bolum = %lf\n", sonuc);
    }
}

void us_alma(double a, int b){
    double sonuc = 1;
    int i;

    if(b<0){
        b = -b;
        for(i=0;i<b;i++){
            sonuc = sonuc*a;
        }
        sonuc = 1/sonuc;
    }
    else if (b==0)
        sonuc = 1;
    else{
        for(i=0;i<b;i++){
            sonuc = sonuc*a;
        }
    }
    printf("Sonuc = %lf\n", sonuc);
}

void veri_alma(double *a, double *b, int us_mu){
    if(us_mu==0){
        printf("1. sayiyi giriniz: ");
        scanf("%lf", a);
        printf("2. sayiyi giriniz: ");
        scanf("%lf", b);
    }
    else{
        int us;
        printf("Tabani giriniz: ");
        scanf("%lf", a);
        printf("Ussu giriniz(tam sayi olmali): ");
        scanf("%d", &us);
        *b = (double) us;
    }
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