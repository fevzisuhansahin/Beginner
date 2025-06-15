#include<stdio.h>
#include<math.h>
#define MAX 10
void polyPrint(int p[][2], int n);
void calculatePoly(int *arr, int n, int x);
int main(){
	//Ax^n + Bx^(n-1) + .... + Lx^0
	
	int poly[MAX][2]={{2,3}, {-4,1}, {5,4}};//2x^3 - 4x + 5x^4
	polyPrint(poly,MAX);
	//calculatePoly(poly, MAX, 2);
}
void polyPrint(int p[][2], int n){
	int i;
	for(i=0;i<n-1;i++){
		if(p[i][0]!=0)
		printf("%d X^%d+",p[i][0],p[i][1]);	
	}
	if(p[i][0]!=0)
	printf("%d X^%d",p[i][0],p[i][1])	;
}

void calculatePoly(int *arr, int n, int x){
	int i;
	int value = 0;
	for(i=0;i<n;i++){
		value += pow(x,i)*arr[i];		
	}
	printf("\nResult P(%d) = %d",x,value);
}
