#include<stdio.h>
#include<stdlib.h>
int main(){
	double **ptr_food;
	double **ptr_other;
	double *basket;
	int item;
	int i;
	int type; // 0-1
	int size1=2, size2=2;
	int counter1=0, counter2=0;
	
	printf("Enter item number"); scanf("%d",&item);
	basket=(double *)calloc(item,sizeof(double));
	
	ptr_food=(double **)calloc(size1,sizeof(double *));
	ptr_other=(double **)calloc(size2,sizeof(double *));
	
	for(i=0;i<item;i++)
	{
	   printf("Enter %dth price",(i+1));
	   scanf("%lf",&basket[i]);
	   printf("Enter type of %dth product <0 or 1>",(i+1));
	   scanf("%d",&type);
	   if(type==0){
	   		if(counter1==size1){
	   			printf("food list reallocated\n");
				   size1*=2; 
	   			ptr_food=(double **)realloc(ptr_food,size1*sizeof(double *));
			}
		   ptr_food[counter1]=&basket[i];
		   counter1++;			
	   }
	   else{
	       	if(counter2==size2){
	   			printf("other list reallocated\n");
				   size2*=2; 
	   			ptr_other=(double **)realloc(ptr_other,size2*sizeof(double *));
		   }	 
		   ptr_other[counter2]=&basket[i];
		   counter2++;			
	   	} 
			 //printf("%d . elm:%f",i,basket[i]);			
	}
	printf("\nFOODS--------\n");
	for(i=0;i<counter1;i++){
		printf("%p %lf \n",ptr_food[i],*(ptr_food[i]));
		
	}
	printf("\nOTHERS--------\n");
	for(i=0;i<counter2;i++){
		printf("%p %lf \n",ptr_other[i],*(ptr_other[i]));
		
	}	
}

