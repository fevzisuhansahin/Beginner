#include <stdio.h>
void printArray(double arr[], int n);
void printArrayv2(double *arr, int n);
void foov2(double arr[], int n);
void foo(double *arr, int n);
void foov3(double *arr, int n);
int main(){
	double d[5]={1,2,3,4,5}, *dp;
	int i;
	printf("%p %p %p %p\n",d,&d, &d[0], d[0]);
	dp = d; // dp= &d[0]
	*(dp+3) = 50;
	printf("%p %lf %lf\n",dp+3, *dp+3, *(dp+3)); 
	printArray(d,5);
	printArrayv2(d,5);
	foo(d,5);
	printArrayv2(d,5);
	foov2(d,5);
	printArrayv2(d,5);
	foov3(d,5);
	printArrayv2(d,5);
	/*for(i = 0;i<5;i++){ // illegal
		d++;
	}*/
	return 0;
}

void printArray(double arr[], int n){
	int i;
	for(i=0;i<n;++i){
		printf("%lf ",arr[i]);
	}
	printf("\n");
}

void printArrayv2(double *arr, int n){
	int i;
	for(i=0;i<n;++i){
		//printf("%lf ",*(arr+i));
		printf("%lf ",arr[i]);
	}
	printf("\n");
}

void foo(double *arr, int n){ //arr: call by ref/pointer
	int i;
	for(i=0;i<n;++i){
		*(arr+i) = 5;
	}

}

void foov2(double arr[], int n){ // arr: call by ref/pointer
	int i;
	for(i=0;i<n;++i){
		arr[i] = 2;
	}

}

void foov3(double *arr, int n){ // arr: call by ref/pointer
	int i;
	double *p = arr;
	for(i=0;i<n;++i){
		*arr = 9;
		arr++;
	}
	//printf("%d",__LINE__);
	*(p+3) = 7;
	//printf("%d",__LINE__);
	*(arr+3) = 7;
}
