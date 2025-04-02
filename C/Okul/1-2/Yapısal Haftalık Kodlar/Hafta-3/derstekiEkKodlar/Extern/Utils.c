// utils.c

#include <stdio.h>

// Bu değişken başka dosyadan erişilebilecek
int globalVar = 42;

// Fonksiyonun tanımını yapıyoruz
void printGlobalVar() {
    printf("Global Variable: %d\n", globalVar);
}
