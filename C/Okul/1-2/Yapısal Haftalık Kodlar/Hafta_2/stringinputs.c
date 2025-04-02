#include <stdio.h>
#include <string.h>
#define MAX 100
int main(){
	int dizi[MAX]={0};
	char isim[MAX];
	
	printf("Isim giriniz");
	scanf("%[^\n]s",isim);
	printf("Girilen isim:%s",isim);
	
	//scanf("%d-%d",&s1,&s2);
	
	char s1[100],ch;
	int x, y;
	//printf("%d %d\n",x,y);
	printf("Please enter two numbers separated by a space\n");
	//fflush(stdin);
	scanf("%c",&ch);
	printf("aaa%cbbb %d",ch,ch);
	
	/*fgets( s1, sizeof(s1), stdin);
	sscanf( s1, "%d %d", &x, &y ); 
	printf("%d %d",x,y);*/
	
	return 0;
}
