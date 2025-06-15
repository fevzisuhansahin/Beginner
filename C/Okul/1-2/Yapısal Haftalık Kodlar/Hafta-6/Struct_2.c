#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	int id;
	int age;
	char name[47];
	char gender;
	//struct student *s;	
} STUDENT;

//typedef struct student STUDENT;
void printInfo(STUDENT s);
void printList(STUDENT *list, int n);
#define MAX 10
int main(){
	STUDENT s1;
	STUDENT stdArray[MAX];
	int N, i;
	STUDENT *ps1, **ps2; 
	ps1 = &s1;
	ps2 = &ps1;
	ps1 = (STUDENT*)malloc(N*sizeof(STUDENT));
	for(i=0;i<N;i++){
		scanf("%d %s %d %c",&ps1[i].id, ps1[i].name,&ps1[i].age,&ps1[i].gender);
	}
	
	for(i=0;i<MAX;i++){
		scanf("%d %s %d %c",&stdArray[i].id, stdArray[i].name,&stdArray[i].age,&stdArray[i].gender);
	}
	
	free(ps1);
}
void printList(STUDENT *list, int n){
	int i;
	for(i=0;i<n;i++){
		//printf("%d, %s, %d, %c\n",list[i].id, list[i].name,list[i].age,list[i].gender);
		printInfo(list[i]);
	}
}
void printInfo(STUDENT s){//call by value
	//printf("Info:\n");
	printf("%d %s %d %c\n",s.id,s.name,s.age,s.gender);
}

void f(int x){
	
}
