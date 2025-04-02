#include <stdio.h>
#define MAX 100
int main(){

	int i;
	int N;
	
	printf("N degeri "); scanf("%d",&N);
	int grades[MAX];
	int grades2[MAX][3];
	int max = 0;
	
	for(i=0;i<N;i++){
		printf("Not giriniz"); scanf("%d",&grades[i]);
		if(grades[i]>grades[max]){ // 20 34 23 7 
			max = i;
		}
	}
	//sort(grades);
	//trade-off
	printf("Max and max index respectively, %d, %d\n",grades[max], max);
    printf("%p %p %d %d",grades,&grades[0],grades[2],2[grades])	; // grades + 2*sizeof(grades[2])
	//grades[k]
   return 0;
}

