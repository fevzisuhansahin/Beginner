#include <stdio.h>
#include <stdlib.h>
int fillMatrix(int **, int , int );
void printMatrix(int **, int , int );
void freeMatrix(int **, int );
int** allocateMatrix(int , int );
int** convertMatrix(int **matrix, int row, int col, int c);
int main(){
	srand(time(NULL));
	int row, col;
	int **matrix, **matrix2;
	int c;
	printf("Enter row and col, respectively");
	scanf("%d %d",&row,&col);
	matrix = (int**)allocateMatrix(row,col);
	c = fillMatrix(matrix,row, col);
	printf("%d\n",c);
	
	printMatrix(matrix,row, col);
	matrix2 = convertMatrix(matrix, row, col, c);
	printMatrix(matrix2,c, 2);
	
	freeMatrix(matrix, row);
	freeMatrix(matrix2, c);
	return 0;	
}
int** convertMatrix(int **matrix, int row, int col, int c){
	int **m=allocateMatrix(c,2);
	int i,j, k=0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(matrix[i][j]){
				m[k][0] = i;
				m[k][1] = j;
				k++;	
			}
		}
	}
	
	return m;
}


int fillMatrix(int **matrix, int row, int col){
	int i, j, c=0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			c += matrix[i][j] = rand() % 2;		
		}
	}
	return c;
}

void printMatrix(int **matrix, int row, int col){
	int i, j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%2d",matrix[i][j]);
		}
		printf("\n");
	}
}

void freeMatrix(int **matrix, int row){
	int i;
	for(i=0;i<row;i++){
		free(matrix[i]);
	}
	free(matrix);
}

int** allocateMatrix(int row, int col){
	int** m;
	int i;
	m = (int**) calloc(row,sizeof(int*));
	for(i =0;i<row;i++){
		m[i] = (int*) calloc(col,sizeof(int));
	}	
	return m;
}
