#include <stdio.h>
#include <string.h>

  void f();
  void g();
int main(){
	int x=0;
	int dizi[5]={0};
	int *dizi2 = malloc(5*sizeof(int));
	printf("%p\n",&x);				// 0061FF18
	printf("%p\n",&dizi[0]);		// 0061FF04
    printf("%p\n",dizi2);			// 00C916C0

	f();
	g();
	return 0;
}

void f(){
	
	int x=0;
	int dizi[5]={0}; // dynamic duraion
	int *dizi2 = malloc(5*sizeof(int)); // static duration
	printf("%p\n",&x);				// 0061FED8
	printf("%p\n",&dizi[0]);		// 0061FEC4
	printf("%p\n",dizi2);			// 00C916E0
	free(dizi2);
}

void g(){
	
	int x=0;
	int dizi[5]={0};
	int *dizi2 = malloc(5*sizeof(int));
	printf("%p\n",&x);				// 0061FED8
	printf("%p\n",&dizi[0]);		// 0061FEC4
	printf("%p\n",dizi2);			// 00C916E0
}
