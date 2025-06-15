#include<stdio.h>
#include<stdlib.h>
int multiplyArray(int *a1, int *a2, int n);
int** createMatrix(int m, int n);
void fillMatrix(int** matrix, int m, int n);
void printMatrix(int** matrix, int m, int n);
int** multiplyMatrices(int **m1, int m, int n, int **m2,int k, int l);
int main(){
	int m, n;
	int k, l;
	int **m1, **m2, **m3;
	printf("Enter m and n for matrix1");
	scanf("%d %d",&m, &n);
	m1 = createMatrix(m,n);
	printf("Enter k and n for matrix2");
	scanf("%d %d",&k, &l);
	m2 = createMatrix(k,l);
	fillMatrix(m1,m,n);
	fillMatrix(m2,k,l);
	printMatrix(m1,m,n);
	printMatrix(m2,k,l);
	m3 = multiplyMatrices(m1,m,n,m2,k,l);
	printMatrix(m3,m,l);
	return 0;
}

int** createMatrix(int m, int n){
	int **matrix;
	int i;
	matrix = (int**)calloc(m,sizeof(int*));
	if(matrix==NULL){
		return NULL;
	}
	for(i=0;i<m;i++){
		matrix[i]=(int*)calloc(n,sizeof(int));
		if(matrix[i]==NULL){
			return NULL;
		}
	}		
	return matrix;
}

void fillMatrix(int** matrix, int m, int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			matrix[i][j] = rand() % (m+n) +1 ;
		}
	}
}

void printMatrix(int** matrix, int m, int n){
	int i,j;
	printf("\n================\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%3d",matrix[i][j]);
		}
		printf("\n");
	}
}

int** multiplyMatrices(int **m1, int m, int n, int **m2,int k, int l){
	if(n!=k) return;
	int **m3 = createMatrix(m,l);
	int i, j, x;
	int *tmp = calloc(n,sizeof(int));
	for(i=0;i<m;i++){
		for(j=0;j<l;j++){
			/*for(x=0;x<n;x++){
				m3[i][j] += m1[i][x]*m2[x][j];
			}*/
			for(x=0;x<n;x++){
				tmp[x] = m2[x][j];
			}
			m3[i][j] = multiplyArray(m1[i],tmp,n);
			
		}
	}
	return m3;
}

int multiplyArray(int *a1, int *a2, int n){
	int i;
	int tp=0;
	for(i=0;i<n;i++){
		tp += a1[i]*a2[i];
	}
	return tp;
}
