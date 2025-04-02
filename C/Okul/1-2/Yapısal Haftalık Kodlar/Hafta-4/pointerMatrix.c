#include <stdio.h>
#define M 3
void printMatrix(int m[][M],int r);
int main(){

	int m[M][M]={{1,2},{3,4,5},{6}};
	printMatrix(m,M);

}

void printMatrix(int m[][M],int r){
	int i,j;
	for(i=0;i<r;i++){
		//printf("%p:",m[i]);
		printf("%p:",m+i);
		//printf("%d:",*(*(m+i)+1));
		for(j=0;j<M;j++){		
			//printf("%d",m[i][j]);
			//printf("%d ",*(m[i]+j));
			printf("%d ",*(*(m+i)+j));
		}
		printf("\n");
	}
}
