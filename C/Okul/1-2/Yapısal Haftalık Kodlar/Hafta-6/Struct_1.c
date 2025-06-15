#include <stdio.h>
#include <string.h>

typedef struct student{
	int id;
	int age;
	char name[47];
	char gender;	
} STUDENT;
//typedef struct student STUDENT;
void printInfo(STUDENT s);
int main(){
	int i=5, j;
	j = i;
	struct student s1;
	STUDENT s2;
	printf("%p - %d\n",&i,sizeof(int));
	printf("%p - %d\n",&s1,sizeof(STUDENT));
	printf("%p - %d\n",&s2,sizeof(s2));

	
	printf("Enter id, name, age, gender respectively");
	scanf("%d %s",&s1.id,s1.name); 
	scanf("%d",&s1.age);
	fflush(stdin);
	scanf("%c",&s1.gender);
	
	printInfo(s1);
	s2 = s1; // deep copy except char[]i.e. string
	printInfo(s2);
	strcpy(s1.name,"Deneme");
	s1.id = 0;
	printInfo(s1);
	printInfo(s2);	
}
void printInfo(STUDENT s){//call by value
	printf("Info:\n");
	printf("%d %s %d %c\n",s.id,s.name,s.age,s.gender);
}
