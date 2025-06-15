#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NO 9
#define MAX_NAME 50
#define MAX_ISBN 20
#define MAX_ETIKET 25
#define MAX_TARIH 11
#define MAX_SATIR 256
//---------------------------------------------------
// Yazar(tek yönlü linked list)
typedef struct Yazar{
    int yazarID;
    char* ad;
    char* soyad;
    struct Yazar* next;
} YAZAR;

// Öğrenci(çift yönlü linked list)
typedef struct Ogrenci{
    char* ogrenciNo;  // 8 haneli
    char* ad;
    char* soyad;
    int puan; // Başlangıçta 100
    struct Ogrenci* next;
    struct Ogrenci* prev;
} OGRENCI;

// KİTAP
// her kitabın örneği
typedef struct KitapOrnek{
    char* etiketNo;          // ISBN_1, ISBN_2, ...
    char* rafDurumu;         // "RAFTA" ya da öğrenci no
    struct KitapOrnek* next;
} KITAP_ORNEK;

// Kitap(tek yönlü linked list)
typedef struct Kitap{
    char* kitapAdi;
    char* ISBN;
    int adet;
    struct KitapOrnek* ornekler;
    struct Kitap* next;
} KITAP;

// Kitap-Yazar(tek yönlü linked list)
typedef struct KitapYazar{
    char* isbn;
    char** yazarID;
    int yazarSayisi;
    struct KitapYazar* next;
} KITAP_YAZAR;

// Kitap İşlemleri(tek yönlü linked list)
typedef struct KitapIslem{
    char* ogrenciNo;
    char* etiketNo;
    int islemTuru:1; // 0: Ödünç, 1: Teslim
    char* alisTarihi;       // Kitabın ödünç alındığı tarih
    char* teslimTarihi;     // Teslim edilmesi gereken tarih
    char* iadeTarihi;       // Öğrencinin getirdiği tarih
    struct KitapIslem* next;
} KITAP_ISLEM;
//---------------------------------------------------------
void yazarIslemleri();
YAZAR* yazarEkle(YAZAR* head, char* ad, char* soyad);
YAZAR* yazarSil(YAZAR* head, int yazarID);
YAZAR* yazarGuncelle(YAZAR* head, int yazarID);
void yazarListele();
void yazarBilgisiGoruntule(YAZAR* yazarListesi, KITAP_YAZAR* kitapYazarListesi, KITAP* kitapListesi);
void yazarDosyayaYaz(YAZAR* head);
YAZAR* yazarDosyadanOku();
void yazarBellekTemizle(YAZAR* head);
//-----------------------------------------------------------
void kitapIslemleri();
void kitapEkle(KITAP** kitapListesi, char* kitapAdi, char* ISBN, int adet);
KITAP* kitapSil(KITAP* head, char* ISBN);
void kitapGuncelle(KITAP* head, char* ISBN);
void kitapListele();
void kitapOduncAl(KITAP* kitapHead, KITAP_ISLEM** islemHead, char* ogrenciNo, char* etiketNo);
void kitapIadeEt(KITAP* kitapHead, KITAP_ISLEM** islemHead, char* ogrenciNo);
void kitapAra(KITAP* kitapHead);
void raftakiKitaplariListele();
int tarihKarsilastir(char* t1, char* t2);
void zamaniGecmisKitaplariListele(KITAP_ISLEM* islemListesi);
void kitapDosyayaYaz(KITAP* kitapHead);
void kitapOrnekDosyayaYaz(KITAP* kitaplar);
KITAP* kitapDosyadanOku();
void kitapBellekTemizle(KITAP* head);
//--------------------------------------------------------------------
void kitapIslemDosyayaYaz(KITAP_ISLEM* islemListesi);
KITAP_ISLEM* kitapIslemDosyadanOku();
void kitapIslemBellekTemizle(KITAP_ISLEM* head);
//---------------------------------------------------------------------
void kitapYazarIslemleri(KITAP_YAZAR** Head);
KITAP_YAZAR* kitapYazarEkleGuncelle(KITAP_YAZAR* head);
void kitapYazarDosyayaYaz(KITAP_YAZAR* head);
KITAP_YAZAR* kitapYazarDosyadanOku();
void kitapYazarBellekTemizle(KITAP_YAZAR* head);
//-----------------------------------------------------------
void ogrenciIslemleri();
OGRENCI* ogrenciEkle(OGRENCI* head, char* ad, char* soyad, char* numara);
OGRENCI* ogrenciSil(OGRENCI* head, char* numara);
OGRENCI* ogrenciGuncelle(OGRENCI* head, char* numara);
void ogrenciListele();
void ogrenciBilgisiGoruntule(OGRENCI* ogrenciListesi, KITAP_ISLEM* islemListesi, char* ogrenciNo);
void ogrenciDosyayaYaz(OGRENCI* head);
OGRENCI* ogrenciDosyadanOku();
void ogrenciBellekTemizle(OGRENCI* head);
//-----------------------------------------------------------
int main(){
    int secim;

    while(1){
        printf("\n=== KUTUPHANE OTOMASYONU ===\n");
        printf("1. Ogrenci Islemleri\n");
        printf("2. Kitap Islemleri\n");
        printf("3. Yazar Islemleri\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        getchar();

        switch (secim) {
            case 1:
                ogrenciIslemleri();
                break;
            case 2:
                kitapIslemleri();
                break;
            case 3:
                yazarIslemleri();
                break;
            case 0:
                printf("Cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }
}
//---------------------------------------------------------------------------------------
void yazarIslemleri(){
    int secim,id;
    char* ad = (char*)malloc(MAX_NAME*sizeof(char));
    char* soyad = (char*)malloc(MAX_NAME*sizeof(char));
    if(ad == NULL || soyad == NULL){
        printf("Bellek ayirma hatasi!\n");
        free(ad);
        free(soyad);
        return;
    }

    YAZAR* yazarListesi = yazarDosyadanOku();

    do {
        yazarListesi = yazarDosyadanOku();

        printf("\n=== YAZAR ISLEMLERI ===\n");
        printf("1. Yazar Ekle\n");
        printf("2. Yazar Sil\n");
        printf("3. Yazar Listele\n");
        printf("4. Yazar Guncelle\n");
        printf("0. Geri\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        getchar();

        switch (secim) {
            case 1:
                printf("Ad: ");
                fgets(ad, MAX_NAME, stdin);
                ad[strcspn(ad, "\n")] = '\0';  // newline sil
                
                printf("Soyad: ");
                fgets(soyad, MAX_NAME, stdin);
                soyad[strcspn(soyad, "\n")] = '\0';

                yazarListesi = yazarEkle(yazarListesi, ad, soyad);
                break;
            case 2:
                yazarListele();
                printf("\nSilinecek yazar ID: ");
                scanf("%d", &id);
                yazarListesi = yazarSil(yazarListesi, id);
                yazarDosyayaYaz(yazarListesi);
                break;
            case 3:
                yazarListele(yazarListesi);
                break;
            case 4:
                yazarListele();
                printf("Guncellenecek yazar ID: ");
                scanf("%d", &id);
                yazarListesi = yazarGuncelle(yazarListesi, id);
                yazarDosyayaYaz(yazarListesi);
                break;
            case 0:
                printf("Yazar islemlerinden cikiliyor...");
                break;
            default:
                printf("Gecersiz secim!\n");
        }
    } while (secim != 0);

    yazarBellekTemizle(yazarListesi);
    free(ad);
    free(soyad);
}
YAZAR* yazarEkle(YAZAR* head, char* ad, char* soyad){
    FILE* dosya = fopen("yazarlar.csv", "a");
    if(dosya == NULL){
        printf("Dosya okuma hatasi!\n");
        return NULL;
    }
    YAZAR* yeni = (YAZAR*)malloc(sizeof(YAZAR));
    if(!yeni){
        printf("Bellek ayirma hatasi!\n");
        return head;
    }

    yeni->ad = (char*)malloc(strlen(ad) + 1);
    yeni->soyad = (char*)malloc(strlen(soyad) + 1);
    if(!yeni->ad || !yeni->soyad){
        printf("Bellek ayirma hatasi!\n");
        free(yeni);
        return head;
    }
    strcpy(yeni->ad, ad);
    strcpy(yeni->soyad, soyad);

    yeni->next = NULL;

    // id bul
    int yeniID = 1;
    YAZAR* temp = head;
    while(temp != NULL){
        if(temp->yazarID >= yeniID){
            yeniID = temp->yazarID + 1;
        }
        temp = temp->next;
    }
    yeni->yazarID = yeniID;
    fprintf(dosya, "%d,%s,%s\n", yeni->yazarID, yeni->ad, yeni->soyad);
    printf("Yazar kaydedildi.\n");
    fclose(dosya);

    // yeni id insert et
    if(head == NULL || head->yazarID > yeni->yazarID){
        yeni->next = head;
        return yeni;
    }

    YAZAR* onceki = NULL;
    temp = head;
    while(temp != NULL && temp->yazarID < yeni->yazarID){
        onceki = temp;
        temp = temp->next;
    }
    yeni->next = temp;
    onceki->next = yeni;

    return head;
}
YAZAR* yazarSil(YAZAR* head, int yazarID) {
    if (head == NULL) {
        printf("Yazar listesi bos.\n");
        return NULL;
    }

    YAZAR* temp = head;
    YAZAR* onceki = NULL;
    // basta
    if (temp->yazarID == yazarID) {
        head = temp->next;

        free(temp->ad);
        free(temp->soyad);
        free(temp);

        printf("Yazar (ID: %d) silindi.\n", yazarID);
        return head;
    }

    // arada veya sonda
    while (temp != NULL && temp->yazarID != yazarID) {
        onceki = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Yazar (ID: %d) bulunamadi.\n", yazarID);
        return head;
    }
    onceki->next = temp->next;

    free(temp->ad);
    free(temp->soyad);
    free(temp);

    printf("Yazar (ID: %d) silindi.\n", yazarID);
    return head;
}
YAZAR* yazarGuncelle(YAZAR* head, int yazarID) {
    YAZAR* temp = head;
    while (temp != NULL) {
        if (temp->yazarID == yazarID) {
            char* yeniAd = (char*)malloc(MAX_NAME*sizeof(char));
            char* yeniSoyad = (char*)malloc(MAX_NAME*sizeof(char));
            if(yeniAd == NULL || yeniSoyad == NULL){
                printf("Bellek ayirma hatasi!\n");
                free(yeniAd);
                free(yeniSoyad);
                return NULL;
            }

            printf("Yeni adi girin: ");
            scanf(" %49[^\n]", yeniAd); 
            printf("Yeni soyadi girin: ");
            scanf(" %49[^\n]", yeniSoyad);

            free(temp->ad);
            free(temp->soyad);

            temp->ad = (char*)malloc(strlen(yeniAd) + 1);
            temp->soyad = (char*)malloc(strlen(yeniSoyad) + 1);

            if (temp->ad == NULL || temp->soyad == NULL) {
                printf("Bellek ayirma hatasi!\n");
                return head;
            }

            strcpy(temp->ad, yeniAd);
            strcpy(temp->soyad, yeniSoyad);

            printf("Yazar guncellendi.\n");
            free(yeniAd);
            free(yeniSoyad);

            return head;
        }
        temp = temp->next;
    }

    printf("Yazar bulunamadi.\n");
    return head;
}
void yazarListele(){
    YAZAR* head = yazarDosyadanOku();
    if(head == NULL){
        printf("Yazar bulunamadi.\n");
        return;
    }

    printf("\n--- YAZAR LISTESI ---\n");
    YAZAR* temp = head;
    while(temp != NULL){
        printf("ID: %d, Ad: %s, Soyad: %s\n", temp->yazarID, temp->ad, temp->soyad);
        temp = temp->next;
    }
}
void yazarBilgisiGoruntule(YAZAR* yazarListesi, KITAP_YAZAR* kitapYazarListesi, KITAP* kitapListesi){
    if(yazarListesi == NULL || kitapYazarListesi == NULL || kitapListesi == NULL){
        printf("Yeterli veri bulunmamaktadir.\n");
        return;
    }

    char* ad = (char*)malloc(MAX_NAME*sizeof(char));
    char* soyad = (char*)malloc(MAX_NAME*sizeof(char));
    if(!ad || !soyad){
        printf("Bellek ayrilamadi!\n");
        return;
    }
    printf("Yazar adi: ");
    fgets(ad, sizeof(ad), stdin);
    ad[strcspn(ad, "\n")] = '\0';

    printf("Yazar soyadi: ");
    fgets(soyad, sizeof(soyad), stdin);
    soyad[strcspn(soyad, "\n")] = '\0';

    YAZAR* secilenYazar = NULL;
    YAZAR* tempYazar = yazarListesi;

    while(tempYazar != NULL){
        if(strcmp(tempYazar->ad, ad) == 0 && strcmp(tempYazar->soyad, soyad) == 0){
            secilenYazar = tempYazar;
            tempYazar = NULL;
        }
        else {
            tempYazar = tempYazar->next;
        }
    }

    if(secilenYazar == NULL){
        printf("Yazar bulunamadi.\n");
        return;
    }

    printf("\nYazar Bilgisi:\n");
    printf("ID: %d\n", secilenYazar->yazarID);
    printf("Ad: %s\n", secilenYazar->ad);
    printf("Soyad: %s\n", secilenYazar->soyad);

    printf("\nBu yazara ait kitaplar:\n");
    int i, kitapBulundu = 0;

    KITAP_YAZAR* tempKY = kitapYazarListesi;
    while(tempKY != NULL){
        for(i = 0; i < tempKY->yazarSayisi; i++){
            if(atoi(tempKY->yazarID[i]) == secilenYazar->yazarID){
                KITAP* tempKitap = kitapListesi;
                while(tempKitap != NULL){
                    if(strcmp(tempKitap->ISBN, tempKY->isbn) == 0){
                        printf("------------------------------\n");
                        printf("Kitap Adı: %s\n", tempKitap->kitapAdi);
                        printf("ISBN: %s\n", tempKitap->ISBN);
                        printf("Adet: %d\n", tempKitap->adet);
                        kitapBulundu = 1;
                    }
                    tempKitap = tempKitap->next;
                }
            }
        }
        tempKY = tempKY->next;
    }
    if(!kitapBulundu){
        printf("Bu yazara ait kitap bulunamadi.\n");
    }
}
void yazarDosyayaYaz(YAZAR* head){
    FILE* dosya = fopen("yazarlar.csv", "w");
    if(!dosya){
        printf("Dosya yazma hatasi!\n");
        return;
    }

    YAZAR* temp = head;
    while (temp != NULL) {
        fprintf(dosya, "%d,%s,%s\n", temp->yazarID, temp->ad, temp->soyad);
        temp = temp->next;
    }

    fclose(dosya);
    printf("Yazarlar dosyaya kaydedildi.\n");
}
YAZAR* yazarDosyadanOku(){
    FILE* dosya = fopen("yazarlar.csv", "r");
    if(dosya == NULL){
        printf("Dosya bellek ayrilamadi.");
        return NULL;
    }

    YAZAR* head = NULL;
    char* satir = (char*)malloc(MAX_SATIR*sizeof(char));
    if(!satir){
        printf("Bellek ayrilamadi!");
        return NULL;
    }

    while(fgets(satir, MAX_SATIR, dosya) != NULL){
        char* idStr = strtok(satir, ",");
        char* ad = strtok(NULL, ",");
        char* soyad = soyad = strtok(NULL, "\n");

        if(ad != NULL && soyad != NULL && idStr != NULL){
            YAZAR* yeni = (YAZAR*)malloc(sizeof(YAZAR));
            if(yeni != NULL){
                yeni->yazarID = atoi(idStr);
                yeni->ad = strdup(ad);
                yeni->soyad = strdup(soyad);
                yeni->next = NULL;

                if(head == NULL){
                    head = yeni;
                } 
                else{
                    YAZAR* temp = head;
                    while(temp->next != NULL)
                        temp = temp->next;
                    temp->next = yeni;
                }
            }
        }
    }
    fclose(dosya);
    return head;
}
void yazarBellekTemizle(YAZAR* head) {
    YAZAR* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;

        free(temp->ad);
        free(temp->soyad);
        free(temp);
    }
}
//---------------------------------------------------------------------------------------
void kitapIslemleri(){
    KITAP* kitaplar = kitapDosyadanOku();
    KITAP_ISLEM* islemListesi = kitapIslemDosyadanOku();
    KITAP_YAZAR* kitapYazarListesi = kitapYazarDosyadanOku();
    OGRENCI* ogrenciListesi = ogrenciDosyadanOku();

    char* kitapAdi = (char*)malloc(MAX_NAME*sizeof(char));
    char* isbn = (char*)malloc(MAX_ISBN*sizeof(char));
    char* ogrenciNo = (char*)malloc(MAX_NO*sizeof(char));
    char* etiketNo = (char*)malloc(MAX_ETIKET*sizeof(char));
    char* tarih = (char*)malloc(MAX_TARIH*sizeof(char));

    int adet, secim;
    do{
        kitaplar = kitapDosyadanOku();
        islemListesi = kitapIslemDosyadanOku();
        kitapYazarListesi = kitapYazarDosyadanOku();
        ogrenciListesi = ogrenciDosyadanOku();

        printf("\n=== KITAP ISLEMLERI ===\n");
        printf("1. Kitap Ekle\n");
        printf("2. Kitap Sil\n");
        printf("3. Kitap Guncelle\n");
        printf("4. Kitap Listele\n");
        printf("5. Kitap Odunc Al\n");
        printf("6. Kitap Iade Et\n");
        printf("7. Kitap Ara\n");
        printf("8. Raftaki Kitaplari Listele\n");
        printf("9. Teslim Edilmeyen Kitaplari Listele\n");
        printf("10. Kitap-Yazar Islemleri\n");
        printf("0. Geri Don\n");
        printf("Seciminiz: ");
        scanf("%d",&secim);
        getchar();

        switch(secim){
            case 1:
                printf("Kitabin adi:");
                fgets(kitapAdi, MAX_NAME, stdin);
                kitapAdi[strcspn(kitapAdi, "\n")] = '\0';
                printf("ISBN kodu:");
                fgets(isbn, MAX_ISBN, stdin);
                isbn[strcspn(isbn, "\n")] = '\0';
                printf("Kitabin adedini giriniz: ");
                scanf("%d",&adet);
                kitapEkle(&kitaplar, kitapAdi, isbn, adet);
                break;
            case 2:
                kitapListele(kitaplar);
                printf("Kitabin ISBN kodunu giriniz: ");
                scanf("%s",isbn);
                kitaplar = kitapSil(kitaplar, isbn);
                kitapDosyayaYaz(kitaplar);
                kitapOrnekDosyayaYaz(kitaplar);
                break;
            case 3:
                kitapListele(kitaplar);
                printf("Kitabin ISBN kodunu giriniz: ");
                scanf("%s",isbn);
                kitapGuncelle(kitaplar, isbn);
                kitapDosyayaYaz(kitaplar);
                kitapOrnekDosyayaYaz(kitaplar);
                break;
            case 4:
                kitapListele(kitaplar);
                break;
            case 5:
                ogrenciListele(ogrenciListesi);
                printf("Odunc alacak ogrencinin nosunu giriniz: ");
                scanf("%s",ogrenciNo);
                kitapListele(kitaplar);
                printf("Kitabin etiket kodunu giriniz: ");
                scanf("%s",etiketNo);
                kitapOduncAl(kitaplar, &islemListesi, ogrenciNo, etiketNo);
                kitapDosyayaYaz(kitaplar);
                kitapIslemDosyayaYaz(islemListesi);
                kitapOrnekDosyayaYaz(kitaplar);
                break;
            case 6:
                ogrenciListele(ogrenciListesi);
                printf("Kitap vercek ogrencinin nosunu giriniz: ");
                scanf("%s",ogrenciNo);
                kitapIadeEt(kitaplar, &islemListesi, ogrenciNo);
                kitapDosyayaYaz(kitaplar);
                kitapIslemDosyayaYaz(islemListesi);
                kitapOrnekDosyayaYaz(kitaplar);
                break;
            case 7:
                kitapAra(kitaplar);
                break;
            case 8:
                raftakiKitaplariListele(kitaplar);
                break;
            case 9:
                zamaniGecmisKitaplariListele(islemListesi);
                break;
            case 10:
                kitapYazarIslemleri(&kitapYazarListesi);
                break;
            case 0:
                printf("Kitap islemlerinden cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim!\n");
        }
    } while (secim != 0);

    kitapBellekTemizle(kitaplar);
    kitapIslemBellekTemizle(islemListesi);
    kitapYazarBellekTemizle(kitapYazarListesi);
    free(kitapAdi);
    free(isbn);
    free(ogrenciNo);
    free(etiketNo);
    free(tarih);
    printf("Kitap islemleri tamamlandı.\n");
}
void kitapEkle(KITAP** kitapListesi, char* kitapAdi, char* ISBN, int adet){
    FILE* dosyaKitap = fopen("kitaplar.csv", "a");
    FILE* dosyaOrnek = fopen("kitapOrnekleri.csv", "a");

    if(!dosyaKitap || !dosyaOrnek){
        printf("Dosya acma hatasi!\n");
        if (dosyaKitap) fclose(dosyaKitap);
        if (dosyaOrnek) fclose(dosyaOrnek);
        return;
    }

    int i;
    KITAP* yeniKitap = (KITAP*)malloc(sizeof(KITAP));
    if (yeniKitap == NULL) {
        printf("Bellek ayrilamadi!\n");
        return;
    }

    yeniKitap->kitapAdi = strdup(kitapAdi);
    yeniKitap->ISBN = strdup(ISBN);
    yeniKitap->adet = adet;
    yeniKitap->ornekler = NULL;
    yeniKitap->next = NULL;
    fprintf(dosyaKitap, "%s,%s,%d\n", yeniKitap->kitapAdi, yeniKitap->ISBN, yeniKitap->adet);

    // ISBN_1, ISBN_2
    for (i = 1; i <= adet; i++) {
        KITAP_ORNEK* yeniOrnek = (KITAP_ORNEK*)malloc(sizeof(KITAP_ORNEK));
        if (yeniOrnek != NULL) {
            char buffer[100];
            sprintf(buffer, "%s_%d", ISBN, i);

            yeniOrnek->etiketNo = strdup(buffer);
            yeniOrnek->rafDurumu = strdup("RAFTA");
            yeniOrnek->next = yeniKitap->ornekler;
            yeniKitap->ornekler = yeniOrnek;

            fprintf(dosyaOrnek, "%s,%s\n", yeniOrnek->etiketNo, yeniOrnek->rafDurumu);
        } 
        else
        printf("Bellek ayrilamadi!\n");
    }

    yeniKitap->next = *kitapListesi;
    *kitapListesi = yeniKitap;
    fclose(dosyaKitap);
    fclose(dosyaOrnek);
    printf("Kitap eklendi: %s (ISBN: %s, %d adet)\n", kitapAdi, ISBN, adet);
}
KITAP* kitapSil(KITAP* head, char* ISBN){
    if(head == NULL){
        printf("Kitap listesi bos.\n");
        return NULL;
    }
    KITAP* temp = head;
    KITAP* onceki = NULL;

    // İlk düğüm
    if(strcmp(temp->ISBN, ISBN) == 0){
        head = temp->next;

        KITAP_ORNEK* ornek = temp->ornekler;
        while(ornek != NULL){
            KITAP_ORNEK* silinecek = ornek;
            ornek = ornek->next;
            free(silinecek->etiketNo);
            free(silinecek->rafDurumu);
            free(silinecek);
        }
        free(temp->kitapAdi);
        free(temp->ISBN);
        free(temp);

        printf("Kitap (ISBN: %s) silindi.\n", ISBN);
        return head;
    }
    // Arada veya sonda
    while(temp != NULL && strcmp(temp->ISBN, ISBN) != 0){
        onceki = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Kitap (ISBN: %s) bulunamadi.\n", ISBN);
        return head;
    }

    onceki->next = temp->next;

    KITAP_ORNEK* ornek = temp->ornekler;
    while(ornek != NULL){
        KITAP_ORNEK* silinecek = ornek;
        ornek = ornek->next;
        free(silinecek->etiketNo);
        free(silinecek->rafDurumu);
        free(silinecek);
    }
    free(temp->kitapAdi);
    free(temp->ISBN);
    free(temp);

    printf("Kitap (ISBN: %s) silindi.\n", ISBN);
    return head;
}
void kitapGuncelle(KITAP* head, char* ISBN){
    KITAP* kitap = head;
    while (kitap != NULL && strcmp(kitap->ISBN, ISBN) != 0) {
        kitap = kitap->next;
    }
    if (kitap == NULL) {
        printf("Kitap (ISBN: %s) bulunamadi.\n", ISBN);
        return;
    }
    printf("Kitap bulundu: %s\n", kitap->kitapAdi);

    int secim,i;
    printf("1. Kitap adini guncelle\n");
    printf("2. Kitap adedini arttir\n");
    printf("Seciminiz: ");
    scanf("%d", &secim);
    getchar();

    if (secim == 1) {
        char* yeniAd = (char*)malloc(MAX_NAME*sizeof(char));
        printf("Yeni kitap adi: ");
        fgets(yeniAd, MAX_NAME, stdin);
        yeniAd[strcspn(yeniAd, "\n")] = '\0'; // newline sil

        free(kitap->kitapAdi);
        kitap->kitapAdi = strdup(yeniAd);
        printf("Kitap adi guncellendi.\n");
    }
    else if (secim == 2) {
        int eklenecekAdet;
        printf("Eklenecek kitap adedi: ");
        scanf("%d", &eklenecekAdet);

        int baslangic = kitap->adet + 1;
        int bitis = kitap->adet + eklenecekAdet;

        for (i = baslangic; i <= bitis; i++) {
            KITAP_ORNEK* yeniOrnek = (KITAP_ORNEK*)malloc(sizeof(KITAP_ORNEK));
            if(yeniOrnek != NULL){
                char* buffer = (char*)malloc(MAX_ISBN*sizeof(char));
                sprintf(buffer, "%s_%d", kitap->ISBN, i);

                yeniOrnek->etiketNo = strdup(buffer);
                yeniOrnek->rafDurumu = strdup("RAFTA");
                yeniOrnek->next = kitap->ornekler;
                kitap->ornekler = yeniOrnek;  
            }
            else
                printf("Bellek ayrilamadi\n");            
        }
        kitap->adet += eklenecekAdet;
        printf("Kitap adedi arttirildi.\n");
    }
    else {
        printf("Gecersiz secim.\n");
    }
}
void kitapListele(){
    KITAP* head = kitapDosyadanOku();
    if(head == NULL){
        printf("Listelenecek kitap yok.\n");
        return;
    }

    KITAP* kitap = head;
    printf("\n--- KITAP LISTESI ---");
    while(kitap != NULL){
        printf("\n--------------------------------------\n");
        printf("Kitap Adi  : %s\n", kitap->kitapAdi);
        printf("ISBN       : %s\n", kitap->ISBN);
        printf("Toplam Adet: %d\n", kitap->adet);

        KITAP_ORNEK* ornek = kitap->ornekler;
        int sayac = 1;
        while(ornek != NULL){
            printf("  %d. EtiketNo: %-15s | Raf Durumu: %s\n", sayac++, ornek->etiketNo, ornek->rafDurumu);
            ornek = ornek->next;
        }
        kitap = kitap->next;
    }
}
void kitapOduncAl(KITAP* kitapHead, KITAP_ISLEM** islemHead, char* ogrenciNo, char* etiketNo){
    char* alisTarihi = (char*)malloc(MAX_TARIH*sizeof(char));
    char* teslimTarihi = (char*)malloc(MAX_TARIH*sizeof(char));
    if (!alisTarihi || !teslimTarihi) {
        printf("Bellek ayrılamadi!\n");
        return;
    }

    time_t simdi;
    struct tm *zaman;
    time(&simdi);
    zaman = localtime(&simdi);
    strftime(alisTarihi, MAX_TARIH, "%d/%m/%Y", zaman);

    time_t teslimZamani = simdi + (15 * 24 * 60 * 60); // 15 gün * 24 saat * 60 dk * 60 sn
    struct tm *teslimTm = localtime(&teslimZamani);
    strftime(teslimTarihi, MAX_TARIH, "%d/%m/%Y", teslimTm);

    KITAP* kitap = kitapHead;
    while(kitap != NULL){
        KITAP_ORNEK* ornek = kitap->ornekler;
        while(ornek != NULL){
            if(strcmp(ornek->etiketNo, etiketNo) == 0){
                if(strcmp(ornek->rafDurumu, "RAFTA") == 0){
                    free(ornek->rafDurumu);
                    ornek->rafDurumu = strdup(ogrenciNo);

                    KITAP_ISLEM* yeniIslem = (KITAP_ISLEM*)malloc(sizeof(KITAP_ISLEM));
                    if (yeniIslem == NULL) {
                        printf("Bellek ayrilamadi!\n");
                        return;
                    }
                    yeniIslem->ogrenciNo = strdup(ogrenciNo);
                    yeniIslem->etiketNo = strdup(etiketNo);
                    yeniIslem->alisTarihi = strdup(alisTarihi);
                    yeniIslem->teslimTarihi = strdup(teslimTarihi);
                    yeniIslem->iadeTarihi = NULL;
                    yeniIslem->islemTuru = 0; // 0: ödünç
                    yeniIslem->next = *islemHead;
                    *islemHead = yeniIslem;

                    printf("Kitap \"%s\" (Etiket: %s) ogrenci %s tarafindan odunc alindi.\n", kitap->kitapAdi, etiketNo, ogrenciNo);
                    return;
                } 
                else{
                    printf("HATA: Bu kitap zaten odunc alinmis. (Durum: %s)\n", ornek->rafDurumu);
                    return;
                }
            }
            ornek = ornek->next;
        }
        kitap = kitap->next;
    }
    printf("HATA: Etiket numarasina ait kitap bulunamadi: %s\n", etiketNo);
}
void kitapIadeEt(KITAP* kitapHead, KITAP_ISLEM** islemHead, char* ogrenciNo){
    char* iadeTarihi = (char*)malloc(MAX_TARIH*sizeof(char));
    if (!iadeTarihi) {
        printf("Bellek ayrılamadi!\n");
        return;
    }

    time_t simdi;
    struct tm *zaman;
    time(&simdi);
    zaman = localtime(&simdi);
    strftime(iadeTarihi, MAX_TARIH, "%d/%m/%Y", zaman);
    
    KITAP* kitap = kitapHead;
    int bulundu = 0;

    printf("Ogrenci no: %s\n", ogrenciNo);
    printf("Ogrencinin odunc aldigi kitaplar:\n");

    while(kitap != NULL){
        KITAP_ORNEK* ornek = kitap->ornekler;
        while(ornek != NULL){
            if(strcmp(ornek->rafDurumu, ogrenciNo) == 0){
                printf("- Kitap Adı: %s, Etiket No: %s\n", kitap->kitapAdi, ornek->etiketNo);
                bulundu = 1;
            }
            ornek = ornek->next;
        }
        kitap = kitap->next;
    }

    if(!bulundu){
        printf("Bu ogrenciye ait iade edilecek kitap bulunamadi.\n");
        return;
    }

    char* etiketNo = (char*)malloc(MAX_ETIKET*sizeof(char));
    printf("Iade edilecek kitabin etiket numarasini girin: ");
    scanf("%s", etiketNo);

    kitap = kitapHead;
    while(kitap != NULL){
        KITAP_ORNEK* ornek = kitap->ornekler;
        while(ornek != NULL){
            if(strcmp(ornek->etiketNo, etiketNo) == 0 && strcmp(ornek->rafDurumu, ogrenciNo) == 0){
                free(ornek->rafDurumu);
                ornek->rafDurumu = strdup("RAFTA");

                KITAP_ISLEM* yeniIslem = (KITAP_ISLEM*)malloc(sizeof(KITAP_ISLEM));
                yeniIslem->ogrenciNo = strdup(ogrenciNo);
                yeniIslem->etiketNo = strdup(etiketNo);
                yeniIslem->islemTuru = 1; // Teslim
                yeniIslem->iadeTarihi = strdup(iadeTarihi);
                yeniIslem->next = *islemHead;
                *islemHead = yeniIslem;

                printf("Kitap başarıyla iade edildi.\n");
                return;
            }
            ornek = ornek->next;
        }
        kitap = kitap->next;
    }
    printf("Hata: Etiket numarasi bulunamadi veya bu ogrenciye ait degil.\n");
}
void kitapAra(KITAP* kitapHead){
    int secim;
    printf("Arama turunu secin:\n");
    printf("1. Kitap Adina Gore\n");
    printf("2. ISBN Numarasina Gore\n");
    printf("Seciminiz: ");
    scanf("%d", &secim);
    getchar();

    char* aranan = (char*)malloc(MAX_NAME*sizeof(char));
    printf("Aranacak ifadeyi girin: ");
    scanf(" %[^\n]", aranan); // boşluklu girdi için

    int bulundu = 0;

    KITAP* kitap = kitapHead;
    while(kitap != NULL){
        if((secim == 1 && strstr(kitap->kitapAdi, aranan) != NULL) || (secim == 2 && strcmp(kitap->ISBN, aranan) == 0)){
            printf("\n--- Kitap Bilgisi ---\n");
            printf("Adı   : %s\n", kitap->kitapAdi);
            printf("ISBN  : %s\n", kitap->ISBN);
            printf("Adet  : %d\n", kitap->adet);

            printf("Ornekler:\n");
            KITAP_ORNEK* ornek = kitap->ornekler;
            while(ornek != NULL){
                printf("  Etiket No: %s, Durum: %s\n", ornek->etiketNo, ornek->rafDurumu);
                ornek = ornek->next;
            }
            bulundu = 1;
        }
        kitap = kitap->next;
    }
    if(!bulundu){
        printf("Arama sonucu: Hicbir kitap bulunamadi.\n");
    }
}
void raftakiKitaplariListele(){
    KITAP* kitaplar = kitapDosyadanOku();
    if(kitaplar == NULL){
        printf("Kitap listesi bos!\n");
        return;
    }

    int bulundu = 0;
    KITAP* kitap = kitaplar;
    while(kitap != NULL){
        KITAP_ORNEK* ornek = kitap->ornekler;

        while(ornek != NULL){
            if(ornek->rafDurumu != NULL && strcmp(ornek->rafDurumu, "RAFTA") == 0){
                if(!bulundu){
                    printf("Raftaki Kitaplar:\n");
                    printf("----------------------------------\n");
                    bulundu = 1;
                }
                printf("Kitap Adı: %s\n", kitap->kitapAdi);
                printf("ISBN     : %s\n", kitap->ISBN);
                printf("Etiket No: %s\n", ornek->etiketNo);
                printf("----------------------------------\n");
            }
            ornek = ornek->next;
        }
        kitap = kitap->next;
    }
    if(!bulundu){
        printf("Rafta bulunan kitap yok.\n");
    }
}
int tarihKarsilastir(char* t1, char* t2){
    int g1, a1, y1, g2, a2, y2;
    sscanf(t1, "%d.%d.%d", &g1, &a1, &y1);
    sscanf(t2, "%d.%d.%d", &g2, &a2, &y2);

    if (y1 != y2) return y1 < y2 ? -1 : 1;
    if (a1 != a2) return a1 < a2 ? -1 : 1;
    if (g1 != g2) return g1 < g2 ? -1 : 1;
    return 0;
}
void zamaniGecmisKitaplariListele(KITAP_ISLEM* islemListesi){
    char* bugun = (char*)malloc(MAX_TARIH*sizeof(char));
    time_t simdi;
    struct tm *zaman;
    time(&simdi);
    zaman = localtime(&simdi);
    strftime(bugun, MAX_TARIH, "%d/%m/%Y", zaman);
    
    if(islemListesi == NULL){
        printf("Islem listesi bos!\n");
        return;
    }

    int bulundu = 0;
    KITAP_ISLEM* tmp = islemListesi;

    while(tmp != NULL){
        if(tmp->iadeTarihi == NULL && tarihKarsilastir(tmp->teslimTarihi, bugun) < 0){
            if(!bulundu){
                printf("Zamaninda Teslim Edilmeyen Kitaplar:\n");
                printf("------------------------------------------------------\n");
                bulundu = 1;
            }

            printf("Ogrenci No  : %s\n", tmp->ogrenciNo);
            printf("Etiket No   : %s\n", tmp->etiketNo);
            printf("Alıs Tarihi : %s\n", tmp->alisTarihi);
            printf("Teslim Tarihi: %s\n", tmp->teslimTarihi);
            printf("------------------------------------------------------\n");
        }

        tmp = tmp->next;
    }

    if(!bulundu){
        printf("Zamani gecmis kitap bulunmamaktadir.\n");
    }
}
void kitapDosyayaYaz(KITAP* head){
    FILE* kitapDosya = fopen("kitaplar.csv", "w");
    FILE* ornekDosya = fopen("kitapOrnekleri.csv", "w");

    if(!kitapDosya || !ornekDosya){
        printf("Dosya acma hatasi!\n");
        if (kitapDosya) fclose(kitapDosya);
        if (ornekDosya) fclose(ornekDosya);
        return;
    }

    KITAP* temp = head;
    while(temp != NULL){
        fprintf(kitapDosya, "%s,%s,%d\n", temp->kitapAdi, temp->ISBN, temp->adet);

        KITAP_ORNEK* ornek = temp->ornekler;
        while(ornek != NULL){
            fprintf(ornekDosya, "%s,%s\n", ornek->etiketNo, ornek->rafDurumu);
            ornek = ornek->next;
        }
        temp = temp->next;
    }
    fclose(kitapDosya);
    fclose(ornekDosya);
    printf("Kitaplar ve ornekleri dosyaya kaydedildi.\n");
}
void kitapIslemDosyayaYaz(KITAP_ISLEM* islemListesi){
    FILE* dosya = fopen("kitapOdunc.csv", "w");
    if(!dosya){
        printf("kitapOdunc.csv dosyasi acilamadi!\n");
        return;
    }

    KITAP_ISLEM* temp = islemListesi;
    while(temp != NULL){
        fprintf(dosya, "%s,%s,%d,%s\n", temp->etiketNo, temp->ogrenciNo, temp->islemTuru, temp->alisTarihi);
        temp = temp->next;
    }
    fclose(dosya);
}
void kitapOrnekDosyayaYaz(KITAP* kitaplar){
    FILE* dosya = fopen("kitapOrnekleri.csv", "w");
    if(!dosya){
        printf("kitapOrnekleri.csv dosyası acilamadi!\n");
        return;
    }

    KITAP* tempKitap = kitaplar;
    while(tempKitap != NULL){
        KITAP_ORNEK* tempOrnek = tempKitap->ornekler;
        while(tempOrnek != NULL){
            fprintf(dosya, "%s,%s\n", tempOrnek->etiketNo, tempOrnek->rafDurumu);
            tempOrnek = tempOrnek->next;
        }
        tempKitap = tempKitap->next;
    }
    fclose(dosya);
}
KITAP* kitapDosyadanOku(){
    FILE* kitapDosya = fopen("kitaplar.csv", "r");
    FILE* ornekDosya = fopen("kitapOrnekleri.csv", "r");

    if(!kitapDosya || !ornekDosya){
        if(kitapDosya) fclose(kitapDosya);
        if(ornekDosya) fclose(ornekDosya);
        return NULL;
    }

    KITAP* head = NULL;
    char* satir = (char*)malloc(MAX_SATIR * sizeof(char));

    if(!satir){
        printf("Bellek ayirma hatasi!\n");
        fclose(kitapDosya);
        fclose(ornekDosya);
        return NULL;
    }

    // Kitapları oku
    while(fgets(satir, MAX_SATIR, kitapDosya)){
        char* kitapAdi = NULL;
        char* ISBN = NULL;
        int adet = 0;

        char* token = strtok(satir, ",");
        if(token != NULL){
            kitapAdi = strdup(token);
        }

        if(kitapAdi != NULL){
            token = strtok(NULL, ",");
            if(token != NULL){
                ISBN = strdup(token);
            }
            else{
                free(kitapAdi);
                kitapAdi = NULL;
            }
        }

        if(kitapAdi != NULL && ISBN != NULL){
            token = strtok(NULL, ",\n");
            if(token != NULL){
                adet = atoi(token);
            }
            else{
                free(kitapAdi);
                free(ISBN);
                kitapAdi = NULL;
                ISBN = NULL;
            }
        }

        if(kitapAdi != NULL && ISBN != NULL){
            KITAP* yeniKitap = (KITAP*)malloc(sizeof(KITAP));
            if(yeniKitap != NULL){
                yeniKitap->kitapAdi = kitapAdi;
                yeniKitap->ISBN = ISBN;
                yeniKitap->adet = adet;
                yeniKitap->ornekler = NULL;
                yeniKitap->next = head;
                head = yeniKitap;
            }
            else{
                printf("Bellek ayirma hatasi!\n");
                free(kitapAdi);
                free(ISBN);
            }
        }
    }
    fclose(kitapDosya);

    // Kitap örneklerini oku
    while(fgets(satir, MAX_SATIR, ornekDosya)){
        char* etiketNo = NULL;
        char* rafDurumu = NULL;

        char* token = strtok(satir, ",");
        if(token != NULL){
            etiketNo = strdup(token);
        }

        if(etiketNo != NULL){
            token = strtok(NULL, ",\n");
            if(token != NULL){
                rafDurumu = strdup(token);
            }
            else{
                free(etiketNo);
                etiketNo = NULL;
            }
        }

        if(etiketNo != NULL && rafDurumu != NULL){
            char* altCizgi = strrchr(etiketNo, '_');
            int isbnUzunluk = altCizgi ? (int)(altCizgi - etiketNo) : strlen(etiketNo);
            // +1 sonlandırıcı için
            char* isbnBuf = (char*)malloc((isbnUzunluk + 1) * sizeof(char));
            if(isbnBuf == NULL){
                printf("Bellek ayirma hatasi!\n");
                return NULL;
            }
            else{
                strncpy(isbnBuf, etiketNo, isbnUzunluk);
                isbnBuf[isbnUzunluk] = '\0';
            }

            KITAP* kitap = head;
            while(kitap != NULL && strcmp(kitap->ISBN, isbnBuf) != 0){
                kitap = kitap->next;
            }

            if(kitap != NULL){
                KITAP_ORNEK* yeniOrnek = (KITAP_ORNEK*)malloc(sizeof(KITAP_ORNEK));
                if(yeniOrnek != NULL){
                    yeniOrnek->etiketNo = etiketNo;
                    yeniOrnek->rafDurumu = rafDurumu;
                    yeniOrnek->next = kitap->ornekler;
                    kitap->ornekler = yeniOrnek;
                }
                else{
                    printf("Bellek ayirma hatasi!\n");
                    free(etiketNo);
                    free(rafDurumu);
                    return NULL;
                }
            }
            else{
                printf("Bellek ayirma hatasi!\n");
                free(etiketNo);
                free(rafDurumu);
                return NULL;
            }
        }
    }
    free(satir);
    fclose(ornekDosya);
    return head;
}
KITAP_ISLEM* kitapIslemDosyadanOku(){
    FILE* dosya = fopen("kitapOdunc.csv", "r");
    if(!dosya){
        return NULL;
    }

    KITAP_ISLEM* head = NULL;
    char* satir = (char*)malloc(MAX_SATIR*sizeof(char));
    if(satir == NULL){
        printf("Bellek ayirma hatasi");
    }

    while(fgets(satir, sizeof(satir), dosya)){
        char* token;
        char* etiketNo = NULL;
        char* ogrenciNo = NULL;
        int islemTuru = -1;
        char* tarih = NULL;

        token = strtok(satir, ",");
        if(token != NULL) etiketNo = strdup(token);

        token = strtok(NULL, ",");
        if(token != NULL) ogrenciNo = strdup(token);

        token = strtok(NULL, ",");
        if(token != NULL) islemTuru = atoi(token);

        token = strtok(NULL, ",\n");
        if(token != NULL) tarih = strdup(token);

        if(etiketNo != NULL && ogrenciNo != NULL && tarih != NULL && islemTuru != -1){
            KITAP_ISLEM* yeniIslem = (KITAP_ISLEM*)malloc(sizeof(KITAP_ISLEM));
            if(yeniIslem != NULL){
                yeniIslem->etiketNo = etiketNo;
                yeniIslem->ogrenciNo = ogrenciNo;
                yeniIslem->islemTuru = islemTuru;
                yeniIslem->alisTarihi = tarih;
                yeniIslem->next = head;
                head = yeniIslem;
            }
            else{
                printf("Bellek ayirma hatasi");
                free(etiketNo);
                free(ogrenciNo);
                free(tarih);
                return NULL;
            }
        }
        else{
            printf("Bellek ayirma hatasi");
            if (etiketNo) free(etiketNo);
            if (ogrenciNo) free(ogrenciNo);
            if (tarih) free(tarih);
            return NULL;
        }
    }
    fclose(dosya);
    printf("Kitap islemleri dosyadan yuklendi.\n");
    return head;
}
void kitapBellekTemizle(KITAP* head){
    while(head != NULL){
        KITAP* tempKitap = head;
        head = head->next;

        free(tempKitap->kitapAdi);
        free(tempKitap->ISBN);

        KITAP_ORNEK* ornek = tempKitap->ornekler;
        while(ornek != NULL){
            KITAP_ORNEK* tempOrnek = ornek;
            ornek = ornek->next;

            free(tempOrnek->etiketNo);
            free(tempOrnek->rafDurumu);
            free(tempOrnek);
        }
        free(tempKitap);
    }
}
void kitapIslemBellekTemizle(KITAP_ISLEM* head){
    KITAP_ISLEM* temp;
    while(head != NULL){
        temp = head;
        head = head->next;

        if (temp->etiketNo) free(temp->etiketNo);
        if (temp->ogrenciNo) free(temp->ogrenciNo);
        if (temp->alisTarihi) free(temp->alisTarihi);
        if (temp->iadeTarihi) free(temp->iadeTarihi);
        if (temp->teslimTarihi) free(temp->teslimTarihi);

        free(temp);
    }
}
//----------------------------------------------------------------------------
void kitapYazarIslemleri(KITAP_YAZAR** Head){
    int secim;

    do {
        printf("\n--- KITAP-YAZAR ISLEMLERI ---\n");
        printf("1. Kitap-yazar eslestirme\n");
        printf("2. Kitap-yazar eslesmelerini listele\n");
        printf("0. Geri don\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        getchar(); 

        switch (secim) {
            case 1:
                kitapYazarEkleGuncelle(*Head);
                kitapYazarDosyayaYaz(*Head);
                printf("Eslestirme tamamlandi.\n");
                break;

            case 2: {
                KITAP_YAZAR* temp = *Head;
                int i;
                while (temp != NULL) {
                    printf("\nISBN: %s\n", temp->isbn);
                    for (i = 0; i < temp->yazarSayisi; i++) {
                        printf(" - Yazar ID: %s\n", temp->yazarID[i]);
                    }
                    temp = temp->next;
                }
                break;
            }

            case 0:
                printf("Kitap-yazar islemlerinden cikiliyor...\n");
                break;

            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
                break;
        }

    } while (secim != 0);
}
KITAP_YAZAR* kitapYazarEkleGuncelle(KITAP_YAZAR* head){
    char* ISBN = (char*)malloc(MAX_ISBN*sizeof(char));
    if(ISBN == NULL){
        printf("Bellek ayrilmadi!\n");
        return NULL;
    }
    printf("ISBN girin: ");
    scanf(" %s", ISBN);

    int yazarSayisi, i;
    printf("Kac yazar eklenecek: ");
    scanf("%d", &yazarSayisi);

    for(i = 0; i < yazarSayisi; i++){
        char* yazarId = (char*)malloc(MAX_NO*sizeof(char));
        printf("%d. yazar ID: ", i + 1);
        scanf(" %s", yazarId);

        KITAP_YAZAR* temp = head;
        int eslesmeVarMi = 0;
        i = 0;
        while(temp != NULL && eslesmeVarMi == 0){
            if(strcmp(temp->isbn, ISBN) == 0 && strcmp(temp->yazarID[i], yazarId) == 0){
                eslesmeVarMi = 1;
            }
            temp = temp->next;
            i++;
        }

        if(eslesmeVarMi == 0){
            KITAP_YAZAR* yeni = (KITAP_YAZAR*)malloc(sizeof(KITAP_YAZAR));
            if(yeni != NULL){
                yeni->isbn = strdup(ISBN);
                yeni->yazarID[yeni->yazarSayisi] = strdup(yazarId);
                yeni ->yazarSayisi = yazarSayisi;
                yeni->next = head;
                head = yeni;
                printf("Eklendi: %s - %s\n", ISBN, yazarId);
            }
            else{
                printf("Bellek hatasi! %s - %s eklenemedi.\n", ISBN, yazarId);
                return NULL;
            }
        }
        else{
            printf("Bu kitap-yazar eslemesi zaten var: %s - %s\n", ISBN, yazarId);
        }
    }
    return head;
}
void kitapYazarDosyayaYaz(KITAP_YAZAR* head){
    FILE* dosya = fopen("kitapYazar.csv", "w");
    if(dosya == NULL){
        printf("kitapYazar.csv dosyasi acilamadi!\n");
        return;
    }

    KITAP_YAZAR* temp = head;
    int i = 0;
    while(temp != NULL){
        if(temp->isbn != NULL && temp->yazarID[i] != NULL){
            fprintf(dosya, "%s,%s\n", temp->isbn, temp->yazarID[i]);
        }
        temp = temp->next;
        i++;
    }
    fclose(dosya);
    printf("Kitap-yazar eslesmeleri dosyaya yazildi.\n");
}
KITAP_YAZAR* kitapYazarDosyadanOku(){
    FILE* dosya = fopen("kitapYazar.csv", "r");
    if(dosya == NULL){
        return NULL;
    }

    KITAP_YAZAR* head = NULL;
    char* satir = (char*)malloc(MAX_SATIR*sizeof(char));
    if(satir == NULL){
        printf("Bellek ayrilamadi!");
        return NULL;
    }

    while(fgets(satir, sizeof(satir), dosya)){
        char* isbnToken = strtok(satir, ",");
        char* yazarIdToken = strtok(NULL, ",\n");

        if(isbnToken != NULL && yazarIdToken != NULL){
            char* isbn = strdup(isbnToken);
            char* yazarId = strdup(yazarIdToken);

            KITAP_YAZAR* mevcut = head;
            KITAP_YAZAR* bulundu = NULL;

            while(mevcut != NULL && bulundu == NULL){
                if(strcmp(mevcut->isbn, isbn) == 0){
                    bulundu = mevcut;
                }
                mevcut = mevcut->next;
            }

            if(bulundu != NULL){
                char** yeniDizi = realloc(bulundu->yazarID, sizeof(char*) * (bulundu->yazarSayisi + 1));
                if(yeniDizi != NULL){
                    bulundu->yazarID = yeniDizi;
                    bulundu->yazarID[bulundu->yazarSayisi] = yazarId;
                    bulundu->yazarSayisi += 1;
                    free(isbn); // çünkü yeni düğüm oluşturulmadi
                }
                else {
                    printf("yazarId dizisi buyutulemedi.\n");
                    free(isbn);
                    free(yazarId);
                    return NULL;
                }
            }

            if(bulundu == NULL){
                KITAP_YAZAR* yeni = (KITAP_YAZAR*)malloc(sizeof(KITAP_YAZAR));
                if(yeni != NULL){
                    yeni->isbn = isbn;
                    yeni->yazarID = (char**)malloc(sizeof(char*));
                    if(yeni->yazarID != NULL){
                        yeni->yazarID[0] = yazarId;
                        yeni->yazarSayisi = 1;
                        yeni->next = head;
                        head = yeni;
                    }
                    else{
                        printf("yazarId dizisi olusturulamadi.\n");
                        free(isbn);
                        free(yazarId);
                        free(yeni);
                        return NULL;
                    }
                }
                else{
                    printf("Bellek ayrilamadi!\n");
                    free(isbn);
                    free(yazarId);
                    return NULL;
                }
            }
        }
    }
    fclose(dosya);
    printf("Kitap-yazar eslesmeleri dosyadan yuklendi.\n");
    return head;
}
void kitapYazarBellekTemizle(KITAP_YAZAR* head){
    int i;
    while(head != NULL){
        KITAP_YAZAR* temp = head;
        head = head->next;

        if(temp->isbn != NULL){
            free(temp->isbn);
        }

        if(temp->yazarID != NULL){
            for(i = 0; i < temp->yazarSayisi; i++){
                if(temp->yazarID[i] != NULL){
                    free(temp->yazarID[i]);
                }
            }
            free(temp->yazarID);
        }
        free(temp);
    }
}
//-----------------------------------------------------------------------------------------------
void ogrenciIslemleri(){
    OGRENCI* ogrenciListesi = ogrenciDosyadanOku();
    KITAP_ISLEM* islemListesi = kitapIslemDosyadanOku();

    char* ad = (char*)malloc(MAX_NAME*sizeof(char));
    char* soyad = (char*)malloc(MAX_NAME*sizeof(char));
    char* numara = (char*)malloc(MAX_NAME*sizeof(char));

    if(!ad || !soyad || !numara){
        printf("Bellek ayrılamadi!\n");
        return;
    }

    int secim;
    do {
        ogrenciListesi = ogrenciDosyadanOku();
        islemListesi = kitapIslemDosyadanOku();

        printf("\n=== OGRENCI ISLEMLERI ===\n");
        printf("1. Ogrenci Ekle\n");
        printf("2. Ogrenci Sil\n");
        printf("3. Ogrenci Guncelle\n");
        printf("4. Ogrenci Listele\n");
        printf("5. Ogrenci Bilgisi Goruntule\n");
        printf("0. Geri\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        getchar();

        switch (secim) {
            case 1:
                printf("Ogrencinin adi:");
                fgets(ad, MAX_NAME, stdin);
                ad[strcspn(ad, "\n")] = '\0';
                printf("Ogrencinin soyadi:");
                fgets(soyad, MAX_NAME, stdin);
                soyad[strcspn(soyad, "\n")] = '\0';
                printf("Ogrencinin numarasi:");
                fgets(numara, MAX_NO, stdin);
                numara[strcspn(numara, "\n")] = '\0';
                ogrenciListesi = ogrenciEkle(ogrenciListesi, ad, soyad, numara);
                break;
            case 2:
                ogrenciListele(ogrenciListesi);
                printf("Silinecek ogrencinin numarasi:");
                fgets(numara, MAX_NO, stdin);
                numara[strcspn(numara, "\n")] = '\0';
                ogrenciSil(ogrenciListesi, numara);
                ogrenciDosyayaYaz(ogrenciListesi);
                break;
            case 3:
                ogrenciListele(ogrenciListesi);
                printf("Ogrencinin numarasi:");
                fgets(numara, MAX_NO, stdin);
                numara[strcspn(numara, "\n")] = '\0';
                ogrenciListesi = ogrenciGuncelle(ogrenciListesi, numara);
                ogrenciDosyayaYaz(ogrenciListesi);
                break;
            case 4:
                ogrenciListele(ogrenciListesi);
                break;
            case 5:
                ogrenciListele(ogrenciListesi);
                printf("Ogrencinin numarasi:");
                scanf("%s",numara);
                ogrenciBilgisiGoruntule(ogrenciListesi, islemListesi, numara);
                break;
            case 0:
                printf("Ogrenci islemlerinden cikiliyor.\n");
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
                break;
        }
    } while (secim != 0);

    free(ad);
    free(soyad);
    free(numara);
    ogrenciBellekTemizle(ogrenciListesi);
}
OGRENCI* ogrenciEkle(OGRENCI* head, char* ad, char* soyad, char* numara){
    FILE* dosya = fopen("ogrenciler.csv", "a");
    if(dosya == NULL){
        printf("Dosya okuma hatasi!\n");
        return NULL;
    }
    OGRENCI* yeniOgrenci = (OGRENCI*)malloc(sizeof(OGRENCI));
    if(yeniOgrenci == NULL){
        printf("Bellek ayrilamadi!\n");
        return head;
    }

    yeniOgrenci->ad = (char*)malloc(strlen(ad) + 1);
    yeniOgrenci->soyad = (char*)malloc(strlen(soyad) + 1);
    yeniOgrenci->ogrenciNo = (char*)malloc(strlen(numara) + 1);

    if(yeniOgrenci->ad != NULL && yeniOgrenci->soyad != NULL && yeniOgrenci->ogrenciNo != NULL){
        strcpy(yeniOgrenci->ad, ad);
        strcpy(yeniOgrenci->soyad, soyad);
        strcpy(yeniOgrenci->ogrenciNo, numara);
        yeniOgrenci->puan = 100;

        yeniOgrenci->next = NULL;

        if(head == NULL){
            head = yeniOgrenci;
        }
        else{
            OGRENCI* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = yeniOgrenci;
        }
        fprintf(dosya, "%s,%s,%s,%d\n", yeniOgrenci->ogrenciNo, yeniOgrenci->ad, yeniOgrenci->soyad, yeniOgrenci->puan);
        printf("Ogrenci basarili bir sekilde eklendi.\n");
    }
    else{
        printf("Bellek ayrilamadi!\n");
        free(yeniOgrenci->ad);
        free(yeniOgrenci->soyad);
        free(yeniOgrenci->ogrenciNo);
        free(yeniOgrenci);
    }
    fclose(dosya);
    return head;
}
OGRENCI* ogrenciSil(OGRENCI* head, char* numara){
    OGRENCI* onceki = NULL;
    OGRENCI* simdiki = head;

    while(simdiki != NULL){
        if(strcmp(simdiki->ogrenciNo, numara) == 0){
            if(onceki == NULL){
                head = simdiki->next;
            }
            else{
                onceki->next = simdiki->next;
            }

            free(simdiki->ad);
            free(simdiki->soyad);
            free(simdiki->ogrenciNo);
            free(simdiki);
            printf("Ogrenci silindi.\n");
            return head;
        }
        onceki = simdiki;
        simdiki = simdiki->next;
    }
    printf("Belirtilen numarada bir ogrenci bulunamadi.\n");
    return head;
}
OGRENCI* ogrenciGuncelle(OGRENCI* head, char* numara){
    OGRENCI* temp = head;
    while(temp != NULL){
        if(strcmp(temp->ogrenciNo, numara) == 0){
            char* yeniAd = (char*)calloc(MAX_NAME,sizeof(char));
            char* yeniSoyad = (char*)calloc(MAX_NAME,sizeof(char));
            char* yeniNumara = (char*)calloc(MAX_NO,sizeof(char));

            int ch; // buffer temizliği
            while ((ch = getchar()) != '\n' && ch != EOF);

            printf("Yeni ad (bos birakilirsa degismez): ");
            fgets(yeniAd, MAX_NAME, stdin);
            yeniAd[strcspn(yeniAd, "\n")] = '\0';

            printf("Yeni soyad (bos birakilirsa degismez): ");
            fgets(yeniSoyad, MAX_NAME, stdin);
            yeniSoyad[strcspn(yeniSoyad, "\n")] = '\0';

            printf("Yeni numara (bos birakilirsa degismez): ");
            fgets(yeniNumara, MAX_NO, stdin);
            yeniNumara[strcspn(yeniNumara, "\n")] = '\0';

            if(strlen(yeniAd) > 0){
                free(temp->ad);
                temp->ad = strdup(yeniAd);
               
            }
            if(strlen(yeniSoyad) > 0){
                free(temp->soyad);
                temp->soyad = strdup(yeniSoyad);

            }
            if(strlen(yeniNumara) > 0){
                free(temp->ogrenciNo);
                temp->ogrenciNo = strdup(yeniNumara);
            }
            printf("Ogrenci bilgileri guncellendi.\n");
            return head;
        }
        temp = temp->next;
    }
    printf("Ogrenci bulunamadi.\n");
    return head;
}
void ogrenciListele(){
    OGRENCI* temp = ogrenciDosyadanOku();
    if(temp == NULL){
        printf("Listelenecek ogrenci yok.\n");
        return;
    }
    printf("\n--- OGRENCI LISTESI ---\n");
    while(temp != NULL){
        printf("Ad: %s\n", temp->ad);
        printf("Soyad: %s\n", temp->soyad);
        printf("Numara: %s\n", temp->ogrenciNo);
        printf("---------------------------\n");
        temp = temp->next;
    }
}
void ogrenciBilgisiGoruntule(OGRENCI* ogrenciListesi, KITAP_ISLEM* islemListesi, char* ogrenciNo){
    OGRENCI* ogrenci = ogrenciListesi;

    while(ogrenci != NULL && strcmp(ogrenci->ogrenciNo, ogrenciNo) != 0){
        ogrenci = ogrenci->next;
    }
    if(ogrenci == NULL){
        printf("Ogrenci bulunamadi.\n");
        return;
    }

    printf("Ad: %s\n", ogrenci->ad);
    printf("Soyad: %s\n", ogrenci->soyad);
    printf("Numara: %s\n", ogrenci->ogrenciNo);
    printf("Odunc Aldigi Kitaplar:\n");

    KITAP_ISLEM* islem = islemListesi;
    int kitapBulundu = 0;

    while(islem != NULL){
        if(strcmp(islem->ogrenciNo, ogrenciNo) == 0 && islem->iadeTarihi == NULL){
            printf("Etiket No: %s\n", islem->etiketNo);
            printf("Alis Tarihi: %s\n", islem->alisTarihi);
            printf("-----------------------\n");
            kitapBulundu = 1;
        }
        islem = islem->next;
    }
    if(!kitapBulundu){
        printf("Su anda odunc kitap yok.\n");
    }
}
void ogrenciDosyayaYaz(OGRENCI* head){
    FILE* dosya = fopen("ogrenciler.csv", "w");
    if(dosya == NULL){
        printf("Dosya yazma hatasi!\n");
        return;
    }

    OGRENCI* temp = head;
    while(temp != NULL){
        fprintf(dosya, "%s,%s,%s,%d\n", temp->ogrenciNo, temp->ad, temp->soyad, temp->puan);
        temp = temp->next;
    }
    fclose(dosya);
}
OGRENCI* ogrenciDosyadanOku(){
    FILE* dosya = fopen("ogrenciler.csv", "r");
    if(dosya == NULL){
        return NULL;
    }

    OGRENCI* head = NULL;
    char* satir = (char*)malloc(MAX_SATIR*sizeof(char));
    if(satir == NULL){
        printf("Bellek ayrılamadi!\n");
        return NULL;
    }

    while(fgets(satir, MAX_SATIR, dosya) != NULL){
        char* numara = strtok(satir, ",");
        char* ad = strtok(NULL, ",");
        char* soyad = strtok(NULL, ",");
        char* puanStr = strtok(NULL, "\n");

        if(ad != NULL && soyad != NULL && numara != NULL){
            OGRENCI* yeni = (OGRENCI*)malloc(sizeof(OGRENCI));
            if (yeni != NULL) {
                yeni->ad = strdup(ad);
                yeni->soyad = strdup(soyad);
                yeni->ogrenciNo = strdup(numara);
                yeni->puan = atoi(puanStr);
                yeni->next = head;
                head = yeni;
            }
        }
    }
    fclose(dosya);
    return head;
}
void ogrenciBellekTemizle(OGRENCI* head){
    OGRENCI* temp = head;

    while(temp != NULL){
        OGRENCI* silinecek = temp;
        temp = temp->next;

        free(silinecek->ad);
        free(silinecek->soyad);
        free(silinecek->ogrenciNo);
        free(silinecek);
    }
}