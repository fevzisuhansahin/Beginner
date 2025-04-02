#include <stdio.h>
#include <stdlib.h>
int* f(int N);
int* g();
void h();
int main(){
	h();
	int *p5 = f(10);
	
	int *d5 = g();
	h();
	
	printf("%d %d",*p5,*d5);
	
	return 0;
}
void h(){
	int i,d[10];
	for(i=0;i<10;i++){
		d[i] = 111;
	}
}

int* f(int N){
	int *p;
	//printf("%p\n",p);
	p = malloc(N*sizeof(int));
	p[5] = 5;
	return &p[5];
}

int* g(){
	int d[10];
	//..
	d[5] = 55;
	return &d[5];
}
