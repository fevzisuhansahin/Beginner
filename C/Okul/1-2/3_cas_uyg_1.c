#include<stdio.h>

void toplama(double a,double b);
void cikarma(double a,double b);
void carpma(double a,double b);
void bolme(double a,double b);
void us_alma(double a, int b);
void veri_alma(double *a, double*b, int us_mu);
int hesap_makinesi();

int main(){
    hesap_makinesi();

    return 0;
}

int hesap_makinesi(){

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