#include<stdio.h>
void swap(int *, int *);
void swapv3(int *, int *);
void swapv2(int x, int y);
void swapv4(int **px, int **py);
int main(){
	int i = 2, j=3;
	int *pi, *pj;
	int *ppi;
	int **pi2;
	
	printf("%p %p %p %p\n",&i,&j,&pi,&pj);
	pi = &i;
	printf("%d %d %p %p %d %d %p\n",i,*pi,&i, pi,&*pi,*&*pi,*&pi );
	printf("%d %d\n",i,j); // 2 3
	*pi = 0;
	printf("%d %d\n",i,j); // 0 3
	ppi = pi;
	*ppi = 5;
	printf("%d %d\n",i,j); // 5 3
	
	//ppi = &pi;
	pi2 = &pi;
	**pi2 = 10;
	printf("%d %d\n",i,j); // 10 3
	
	//swap(&i,&j);
	printf("%d %d\n",i,j); // 10 3
	pi = &i;
	pj = &j;
	printf("%d %d\n",*pi,*pj); // 10 3
	swapv3(pi,pj);// error: pi= &j, pj = &i;
	printf("%d %d\n",*pi,*pj); // 10 3
	swapv4(&pi,&pj);
	printf("%d %d\n",*pi,*pj); // 3 10
}

void swapv4(int **px, int **py){
	int *t;
	t = *px;
	*px = *py;
	*py = t;	
}

void swapv3(int *px, int *py){
	int *t;
	t = px;
	px = py;
	py = t;	
}

void swap(int *x, int *y){//call by pointer, shallow/shadow copy
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

void swapv2(int x, int y){ //call by value, deep copy
	int t;
	t = x;
	x = y;
	y = t;
}





