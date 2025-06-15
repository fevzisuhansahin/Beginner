#include <stdio.h>
#include <stdlib.h>
void printList(int *list, int N);
int main(){
	srand(time(NULL));
	int i,j,N;
	int **matrix;
	int *array;
	printf("Enter N value"); scanf("%d",&N);
	array = (int*) malloc(N*sizeof(int));
	for(i = 0; i<N;i++){
		array[i] = rand()%N + 1;
	}
	
	matrix = (int**) malloc(N*sizeof(int*));
	for(i=0;i<N;i++){
		matrix[i] = (int*) malloc(array[i]*sizeof(int));
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<array[i];j++){
			matrix[i][j] = rand() % 8;
			//printf("%2d",matrix[i][j]);	
		}
		//printList(*(matrix+i),array[i]); *(array+i)
		printList(matrix[i],array[i]);
	}
	
	for(i=0;i<N;i++){
		free(matrix[i]);
	}
	free(matrix);
   
	return 0;
}

void printList(int *list, int N){
	int i;
	for(i=0;i<N;i++){
		printf("%2d",list[i]);
	}
	printf("\n");
}
