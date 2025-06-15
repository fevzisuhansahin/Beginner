#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int yuk;
	if(argc==1){
		printf("Program yanlis baslatildi\n");
		printf("En az 3 arguman girilmelidir\n");
		printf("Argumanlarin anlamlari\n");
		printf("Arg-1 ogrenci sayisi, Arg-2 Ders sayisi, Arg-3 Sinav Yeri ");
	}
	else{
		yuk = atoi(argv[1])*atoi(argv[2]);
		printf("Sinav yeri:%s, Toplam Yuk:%d",argv[3],yuk);	
	}
	

	return 0;
}
