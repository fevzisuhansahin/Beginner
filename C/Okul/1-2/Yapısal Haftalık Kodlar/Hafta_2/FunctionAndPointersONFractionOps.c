/* a/b + c/d = x/y */
#include <stdio.h>

#define MAX 20
void get_fraction(int*,int*); // functi declaration, sgnature, prototype
void write_fraction(char[MAX], int x, int y);
void add_fraction(int n1, int d1, int n2, int d2, int *n3, int *d3);
int gcd(int x, int y);
int gcdv2(int x, int y);
int getMin(int x, int y);

int main(){
	
	int n1, d1, n2, d2; // inputs
	int n3, d3; //output
	get_fraction(&n1,&d1); // function call/invoc call by pointer
	get_fraction(&n2,&d2);
	write_fraction("first",n1,d1);
	write_fraction("second",n2,d2);
	add_fraction(n1,d1,n2,d2,&n3,&d3);
	write_fraction("result",n3,d3);
	
	
}

void add_fraction(int n1, int d1, int n2, int d2, int *n3, int *d3){ 
   // deep copy n1, d1, n2, d2
   // shadow, shallow copy n3 d3
	int n, d;
	int obeb;
	n = n1 * d2 + n2 *d1;
	d = d1 * d2;
	obeb = gcdv2(n,d);
	*n3 = n/obeb;
	*d3 = d/obeb;
}

int getMin(int x, int y){
	return x<=y ? x : y;
}

int gcd(int x, int y){
	int min = getMin(x,y);
	while(x%min != 0 || y %min!=0){
		min--;
	}
	return min;
}

int gcdv2(int x, int y){  // 8 4
	int r ;
   //gcd(x,y) = r: x% y, gcd (y, r )
	do{
		r = x % y; 
		x = y;
		y = r;			
	}while(r != 0);
	return x;
}

void get_fraction(int *x, int *y){// function implementation
	printf("Enter nom and denom respectively");
	scanf("%d %d",x,y);
}

void write_fraction(char text[MAX],int x, int y){
	printf("%s\n%d\n___\n%d\n",text,x,y);
}

void swap(int x, int y){
	int t;
	t = x;
	x=y;
	y=t;
}
