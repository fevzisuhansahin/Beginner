#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100

typedef struct Kargo{
    char* takipNo;
    char* gondericiAd;
    char* sehir;
    char* gun;
    char* durum;
    KARGO* next;
} KARGO;

typedef struct Sehir{
    char* sehir;
    int teslimEdildi;
    int beklemede;
    SEHIR* next;
} SEHIR;

char* strcpy_safe(char* str);
KARGO* yeniKargo(char* takipNo, char* ad, char* sehir, char* gun, char* durum);
void kargoEkle(KARGO** head, KARGO* yeni);
void listele(KARGO* head);
void ismeGöreDosyaOluştur(KARGO* head);
void bekleyenlerDosyasınıYaz(KARGO* head);
SEHIR* sehirBulveyaEkle(SEHIR** head, char* sehir);
void rapor(KARGO* head);
void sehirListesiTemizle(SEHIR* head);

int main() {
    FILE* dosya = fopen("kargolar.txt", "r");
    if(dosya == NULL){
        printf("kargolar.txt dosyası açılamadı.\n");
        return 1;
    }

    KARGO* head = NULL;
    char* no1 = (char*)malloc(10 * sizeof(char));
    char* no2 = (char*)malloc(10 * sizeof(char));
    char* takipNo = (char*)malloc(20 * sizeof(char));
    char* ad = (char*)malloc(50 * sizeof(char));
    char* sehir = (char*)malloc(30 * sizeof(char));
    char* gun = (char*)malloc(20 * sizeof(char));
    char* durum = (char*)malloc(20 * sizeof(char));

    if(!no1 || !no2 || !takipNo || !ad || !sehir || !gun || !durum){
        printf("HATA Bellek ayrılamadı!\n");
        free(no1); 
        free(no2); 
        free(takipNo); 
        free(ad); 
        free(sehir); 
        free(gun); 
        free(durum);
        fclose(dosya);
        return 1;
    }

    while(fscanf(dosya, "%s %s %s %s %s %s", no1, no2, ad, sehir, gun, durum) == 6){
        sprintf(takipNo, "%s%s", no1, no2);  // 8 haneli takip no
        KARGO* yeni = yeniKargo(takipNo, ad, sehir, gun, durum);
        kargoEkle(&head, yeni);
    }
    fclose(dosya);

    listele(head);
    ismeGöreDosyaOluştur(head);
    bekleyenlerDosyasınıYaz(head);
    rapor(head);
    return 0;
}

char* strcpy_safe(char* str){
    char* copy = (char*)malloc(strlen(str) + 1);
    if (copy != NULL){ 
        strcpy(copy, str);
        return copy;
    }
    else
        return NULL;
}

KARGO* yeniKargo(char* takipNo, char* ad, char* sehir, char* gun, char* durum){
    KARGO* yeni = (KARGO*)malloc(sizeof(KARGO));
    if (yeni == NULL) {
        printf("HATA: Kargo için bellek ayrılamadı!\n");
        return NULL;
    }

    yeni->takipNo = strcpy_safe(takipNo);
    yeni->gondericiAd = strcpy_safe(ad);
    yeni->sehir = strcpy_safe(sehir);
    yeni->gun = strcpy_safe(gun);
    yeni->durum = strcpy_safe(durum);
    yeni->next = NULL;

    if (!yeni->takipNo || !yeni->gondericiAd || !yeni->sehir || !yeni->gun || !yeni->durum) {
        printf("HATA: Kargo bilgileri için bellek ayrılamadı!\n");
        free(yeni->takipNo);
        free(yeni->gondericiAd);
        free(yeni->sehir);
        free(yeni->gun);
        free(yeni->durum);
        free(yeni);
        return NULL;
    }
    return yeni;
}

void siraliKargoEkle(KARGO** head, KARGO* yeni){
    // başa
    if(*head == NULL || strcmp(yeni->takipNo, (*head)->takipNo) < 0){
        yeni->next = *head;
        *head = yeni;
    }
    // ortaya veya sona
    else{
        KARGO* current = *head;
        while(current->next != NULL && strcmp(current->next->takipNo, yeni->takipNo) < 0){
            current = current->next;
        }
        yeni->next = current->next;
        current->next = yeni;
    }
}

void listele(KARGO* head){
    printf("KARGO Listesi:\n");
    while(head != NULL){
        printf("%s %s %s %s %s\n", head->takipNo, head->gondericiAd, head->sehir, head->gun, head->durum);
        head = head->next;
    }
}

void ismeGöreDosyaOluştur(KARGO* head){
    while(head != NULL){
        char* dosya_adi = (char*)malloc(MAX_CHAR*sizeof(char));
        if(dosya_adi == NULL){
            printf("HATA Bellek ayrılamadı!\n");
            return;
        }
        sprintf(dosya_adi, "%s.txt", head->gondericiAd);
        FILE* fp = fopen(dosya_adi, "a");
        if (fp == NULL) {
            printf("HATA: %s dosyası açılamadı.\n", dosya_adi);
            free(dosya_adi);
            return;
        }
        fprintf(fp, "%s adlı göndericiye ait %s nolu kargo, %s günü %s şehrine gönderildi.\nDurum: %s", head->gondericiAd, head->takipNo, head->gun, head->sehir, head->durum);
        fclose(fp);
        free(dosya_adi);
        head = head->next;
    }
}

void bekleyenlerDosyasınıYaz(KARGO* head){
    FILE* fp = fopen("bekleyenler.txt", "w");
    if(fp == NULL){
        printf("HATA: bekleyenler.txt dosyası açılamadı!\n");
        return;
    }
    while(head != NULL){
        if(strcmp(head->durum, "Beklemede") == 0){
            fprintf(fp, "%s %s %s %s %s\n", head->takipNo, head->gondericiAd, head->sehir, head->gun, head->durum);
        }
        head = head->next;
    }
    fclose(fp);
}

SEHIR* sehirBulveyaEkle(SEHIR** head, char* sehir){
    SEHIR* curr = *head;
    while(curr != NULL){
        if(strcmp(curr->sehir, sehir) == 0)
            return curr;
        curr = curr->next;
    }
    SEHIR* yeni = (SEHIR*)malloc(sizeof(SEHIR));
    if(yeni != NULL){
        strcpy(yeni->sehir, sehir);
        yeni->teslimEdildi = 0;
        yeni->beklemede = 0;
        yeni->next = *head;
        *head = yeni;
        return yeni;
    }
    else{
        printf("HATA Bellek ayrılamadı!\n");
        return NULL;
    }
}

void rapor(KARGO* head){
    SEHIR* istatistik = NULL;
    while(head != NULL){
        SEHIR* sehir = sehirBulveyaEkle(&istatistik, head->sehir);
        if(sehir == NULL){
            printf("HATA: Şehir eklenemedi.\n");
            sehirListesiTemizle(istatistik);
            return;
        }
        if(strcmp(head->durum, "TeslimEdildi") == 0)
            sehir->teslimEdildi++;
        else
            sehir->beklemede++;
        head = head->next;
    }

    FILE* fp = fopen("rapor.txt", "w");
    if(fp == NULL){
        printf("HATA: rapor.txt dosyası açılamadı!\n");
        sehirListesiTemizle(istatistik);
        return;
    }
    SEHIR* temp = istatistik;
    while(temp != NULL){
        fprintf(fp, "%s: TeslimEdildi = %d, Beklemede = %d\n", temp->sehir, temp->teslimEdildi, temp->beklemede);
        temp = temp->next;
    }
    fclose(fp);
    sehirListesiTemizle(istatistik);
}
void sehirListesiTemizle(SEHIR* head){
    while (head != NULL) {
        SEHIR* tmp = head;
        head = head->next;
        free(tmp);
    }
}