// main.c

#include <stdio.h>

// extern ile başka dosyadaki global değişkeni belirtiyoruz
extern int globalVar;

// extern ile başka dosyadaki fonksiyonu belirtiyoruz
extern void printGlobalVar();

int main() {
    // globalVar'ı yazdırıyoruz
    printf("Main: Global Variable: %d\n", globalVar);

    // utils.c dosyasındaki fonksiyonu çağırıyoruz
    printGlobalVar();

    return 0;
}
