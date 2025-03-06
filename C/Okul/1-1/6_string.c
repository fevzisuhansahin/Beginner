#include <stdio.h>
#include <string.h>
#define MAX 15

int main(){
/*
    int num = printf("Hello");  // metnin length değeri num degiskenine tanımlanır
    printf("\n%d", num);

    // strlen()
    char str[] = "fevzisuhansahin";
    int length = strlen(str);

    printf("\nLength of string: %d", length);

    // fgets(name(char), max_size + 1(int), stream)
    char str1[MAX];

    printf("\n1. stringi giriniz: ");
    fgets(str1, MAX+1, stdin);      // there is limit
    printf("\nString: %s", str1);

    // gets(name(char))
    char str2[MAX];

    printf("\n2. stringi giriniz: ");
    gets(str2);                     // there is no limit
    printf("\nString: %s", str2);

    // puts(name(char))
    char *str3 = "Fevzi Suhan";
    puts(str3);
    // or
    puts("\nSahin");
*/
//----------------------------------------
/*
    int n, i;

    printf("Enter the max size: ");
    scanf(" %d", &n);

    char ogr[n];

    for(i=0 ; i<n ; i++){
        printf("%d. karakteri giriniz: ", (i+1));
        scanf(" %c", &ogr[i]);
    }

    ogr[n] = '\0';  // OR ogr[n] = 0;

    printf("%s\n", ogr);
    OR
    for(i=0 ; i<n ; i++){
        printf("%c", ogr[i]);
    }
*/
//--------------------------------------------
/*
    char kelime1[10];
    char kelime2[6];

    printf("1. kelimeyi gir: ");
    scanf("%10s", kelime1);     // Maksimum 10 karakter okunabilir, son karakter '\0' için
    printf("2. kelimeyi gir: ");
    scanf("%5s", &kelime2[0]);  // Maksimum 5 karakter, '\0' için bir alan bırakılır

    puts(kelime1);
    puts(kelime2);
*/
//--------------------------------------------
/*
    //Kucuk harfleri buyuk harf yapma

    char str[MAX];
    int fark = 'A' - 'a', i=0;

    printf("str gir: ");
    scanf("%s", str);

    while(str[i] != '\0'){

        str[i] = str[i] + fark; //OR str[i] += fark;
        i++;

    }

    printf("Yeni str: %s", str);
*/
//----------------------------------------------------------
/*  Sifreleme

    char str1[MAX];                 // char str1[MAX];
    int key, i=0;                   // int key, i=0, yon=1;

    printf("stringi gir: ");        // printf("stringi gir: ");
    scanf("%s", &str1);             // gets(str1);
    printf("keyi gir: ");           // printf("keyi gir: ");
    scanf("%d", &key);              // scanf("%d", &key);

    while(str1[i] != '\0'){         // while(str[i] != '\0'){
                                    //   str1[i] += (key*yon);
        if(i%2 == 0)                //   yon = -yon;
            str1[i] += key;         //   i++;
        else                        // }
            str1[i] -= key;
                                    // puts(str1);
        i++;
    }

    puts(str1);
*/
//---------------------------------------
/*    Histogram

    char letters[] = "abcdefghijklmnopqrstuvwxyz", text[1000];
    int frq[26] = {0}, i=0, j, a, b, indis;

    puts("texti gir: ");
    gets(text);

    while(text[i] != '\0'){ // OR while(text[i]) çünkü non-zero dönecek
        indis = text[i]-'a';
        frq[indis]++;
        i++;
    }

    for(j=0 ; j<26 ; j++){
        printf("%c-", letters[j]);
    }

    printf("\n");
    
    for(j=0 ; j<26 ; j++){
        printf("%d-", frq[j]);
    }

    for(a=0 ; a<26 ; a++){
        printf("\n%c: ", letters[a]);
        for(b=0 ; b<frq[a] ; b++){
            printf("*");
        }
    }
*/
//------------------------------------------------

    // Str Sayiyi İnt Çevirme

    int isaret=1, n, i;
    char ssayi[n];

    puts("kac karakter var: ");
    scanf("%d", &n);
    puts("Ondalikli sayiyi gir: ");
    gets(ssayi);

    if(ssayi[0] == '-'){
        isaret = -isaret;
        i = 1;
    }
    else
        i = 0;

    


    return 0;
}