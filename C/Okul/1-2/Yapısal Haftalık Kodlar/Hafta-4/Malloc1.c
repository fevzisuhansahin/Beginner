#include <stdio.h>
#include <stdlib.h>
void printArray(double *array, int N);
void fillArray(double *array, int N);
int main(){
	int N,i;
	printf("Enter N"); scanf("%d",&N);
	double *array;
	array = (double*) malloc(N*sizeof(double));
	if(array == NULL){
		printf("Error:%d",__LINE__);
		return -1;
	}
	fillArray(array,N);
	printArray(array,N);	
    //...	
	
	
	
	
	free(array);
	return 0;
}

void printArray(double *array, int N){
	int i;
	for(i=0;i<N;i++){
		printf("%3.3lf ",array[i]); //printf("%3.3lf ",*(array+i));		
	}
}

void fillArray(double *array, int N){
	int i;
	for(i=0;i<N;i++){
		printf("Enter a value");
		scanf("%lf",&array[i]); //scanf("%lf",array+i);	
	}	
}
