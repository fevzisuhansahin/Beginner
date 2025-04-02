#include <stdlib.h>
int main(){
	int i,j,N, M;
	scanf("%d %d",&N, &M);
	int **matris;
	matris= (int**) malloc(N*sizeof(int*));
	for(i=0;i<N;i++){
		matris[i] = (int*) malloc(M*sizeof(int));
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			matris[i][j]=5;
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%5d-",(*(matris+i)+j));
		}
		
		printf("\n");
	}
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%5d",*(*(matris+i)+j));
		}
		
		printf("\n");
	}
}
