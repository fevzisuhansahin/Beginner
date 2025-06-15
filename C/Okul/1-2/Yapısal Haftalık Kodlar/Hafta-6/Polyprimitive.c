#include<stdio.h>
#include<math.h>
#define MAX 10
void polyPrint(int *arr, int n);
void calculatePoly(int *arr, int n, int x);
int main(){
	//Ax^n + Bx^(n-1) + .... + Lx^0
	
	int poly[MAX]={2, 4, 0 , 0 , -7};//-7x^4 + 4x + 2
	polyPrint(poly,MAX);
	calculatePoly(poly, MAX, 2);
}
void polyPrint(int *arr, int n){
	int i;
	for(i=n-1;i>0;i--){
		if(arr[i]!=0){
			printf(" %dX^%d +",arr[i],i);
		}
			
	}
	if(arr[i]!=0)
		printf(" %d",arr[i],i);
}

void calculatePoly(int *arr, int n, int x){
	int i;
	int value = 0;
	for(i=0;i<n;i++){
		value += pow(x,i)*arr[i];		
	}
	printf("\nResult P(%d) = %d",x,value);
}
