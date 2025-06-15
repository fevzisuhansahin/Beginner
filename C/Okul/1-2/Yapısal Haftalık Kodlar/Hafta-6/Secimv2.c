// Seçim sistemleri
// En çok oyu alan partiyi bulmak (N seçmen sayýsý, N elemanlý bir dizi)
#include <stdio.h>
int main()
{
	char oylar[10][3]; //[ 2 5 2 1 3 3 7 ... ]
	int p[10]={0};
	int max = 0;
	int c=0;
	int n,i,j,kazanan,partiSay=0;
	// n secmen sayisi 
	// 1,2,3,4 .. parti numaralari
	scanf ("%d",&n);
	
	for (i=0;i<n;i++){
		scanf("%d %d %d",&oylar[i][0], &oylar[i][1], &oylar[i][2]);
	} //[ {2 5 3}, {1 3 2},.... ]
	
	for(i=0;i<n;i++){ // 0 0 2 0 0 1 0 0 
		for(j=0;j<3;j++){
			p[oylar[i][j]]++;
		}		
	}
	
	max = 0;
	for(i=1;i<n;i++){ // 0 0 2 0 0 1 0 0 
		if(p[i]>p[max]){
			max = i;
		}
	}
	printf("%d-%d",max,p[max]);
	

	
	return 0;	
}

