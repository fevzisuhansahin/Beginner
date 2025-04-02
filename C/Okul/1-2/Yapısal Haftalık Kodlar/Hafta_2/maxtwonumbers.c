#include <stdio.h>

int main(){
	int grade;
	int max = 0, max2=0;
	int max_i, max_ii;
	int i;
	int N;
	printf("N degeri "); scanf("%d",&N);
	for(i=1;i<=N;i++){
		// t = i , i= i+1, return t : i++
		// i = i + 1, return i : ++i
		printf("Not giriniz"); scanf("%d",&grade);
		if(grade>max){
			max2 = max;
			max_ii = max_i;
			max = grade;
			max_i=i;
		}
		else if(grade>max2){
			max2 = grade;
			max_ii=i;
		}
	}
	
	printf("Max and max index respectively, %d, %d\n",max, max_i);
	printf("Second Max and max index respectively, %d, %d",max2, max_ii);

}

