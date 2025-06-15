#include <stdio.h>
#include <stdlib.h>
void printList(int *list, int N);
int* doSth(int n);
int main(){
	int N, M, *p;
	int *array, *tmp;
	char c;
	int state=1;
	printf("Enter N value"); scanf("%d",&N);
	array = (int*) malloc(N*sizeof(int));
	printList(array,N);
	if(array==NULL){
		printf("Error-1"); return -1;
	}	
	do{
		printf("Enter M value"); scanf("%d",&M);
		N = N + M;
		tmp = (int*) realloc(array,sizeof(int)*(N));
		if(tmp == NULL){
			printf("Error-2");// return -2;
			state = 0;
		}
		else{
			array = tmp;	
		}
		printList(array,N);
		
		printf("To go on, enter Y"); 
		fflush(stdin);
		scanf("%c",&c);
	}while((c=='Y' || c=='y')&& state==1);
	
	//
	array[5] =0;
	
	p = doSth(5);
	//
	free(array);
	return 0;
}
void printList(int *list, int N){
	int i;
	printf("Print List method\n");
	for(i=0;i<N;i++){
		printf("%d\n",list[i]);
	}
	printf("=========================\n");
}
/* hatali 
int[] doSth(int n){
	
} */
/* hatali 
int* doSth(int n){
	int d[5];//stack
	return d;	
}
*/

int* doSth(int n){
	int *d;//stack
	d = malloc(5*sizeof(int));
	return d;	
}
