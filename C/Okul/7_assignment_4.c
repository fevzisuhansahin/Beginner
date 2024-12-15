#include <stdio.h>

#define max 100

int main(){

    int n, m, i, j;

    printf("Kac satir olacak: ");
    scanf("%d", &n);                // satir ve sutun sayilarini aldim
    printf("Kac sutun olacak: ");
    scanf("%d", &m);

    int mat[max][max];
    int visited[max][max] = {0.0};  // daha önce ugradigim hucreleri tutmak icin tanimladigim dizi
    

    for(i=0 ; i<n ; i++){           // kullanicidan matrisi aldim
        printf("%d. satir elemanlarini giriniz\n", (i+1));
        for(j=0 ; j<m ; j++){
            printf("%d. eleman : ",(j+1));
            scanf("%d", &mat[i][j]);
        }
    }

    int sayac=0, adet;
    int rows[n];        // yolların satir bilgisini tutan dizi
    int columns[n];      // yollarin sutun bilgisini tutan dizi

    for(i=0 ; i<n ; i++){   // 1. sutundaki yol başlangiclarini belirledim
        if(mat[i][0] != 0){
            rows[i-sayac] = i;
            columns[i-sayac] = 0;
            visited[i][0] = 1;
        }
        else
            sayac++;
    }

    adet = n - sayac;   // kac tane yol olduğunu hesapladım

    int uzunluk[adet], durum[adet]; // yol uzunluklarini ve devam durumunu tutacak diziler tanimladim

    for(i=0 ; i<adet ; i++){
        uzunluk[i] = 0;
        durum[i] = 1;
    }

    for(i=0 ; i<adet ; i++){
        int r = rows[i];
        int c = columns[i];

        while(durum[i] && c < m){
            int curr = mat[r][c];

            if((r-1)>= 0 && mat[r-1][c] == curr && !visited[r-1][c]){    // üstündeki hücreyi kontrol
                r = r-1;
            }
            else if((r+1)<n && mat[r+1][c] == curr && !visited[r+1][c]){   // altindaki hücreyi kontrol
                r = r+1;
            }
            else if((c+1)<m && mat[r][c+1] == curr && !visited[r][c+1]){   // sagindaki hücreyi kontrol
                c = c+1;
            }
            else if((r-1)>=0 && (c+1)<m && mat[r-1][c+1] == curr && !visited[r-1][c+1]){ // sağ üst hücreyi kontrol
                r = r-1;
                c = c+1;
            }
            else if((r+1)<n && (c+1)<m && mat[r+1][c+1] == curr && !visited[r+1][c+1]){ // sağ alt hücreyi kontrol
                r = r+1;
                c = c+1;
            }
            else if((r-1)>=0 && (c-1)>=0 && mat[r-1][c-1] == curr && !visited[r-1][c-1]){ // sol üst hücreyi kontrol
                r = r-1;
                c = c-1;
            }
            else if((r+1)<n && (c-1)>=0 && mat[r+1][c-1] == curr && !visited[r+1][c-1]){ // sol alt hücreyi kontrol
                r = r+1;
                c = c-1;
            }
            else{
                if(c != (m-1))
                    durum[i] = 0;
                else{
                    visited[r][c] = 1;
                    uzunluk[i]++;
                    break;
                }
            }

            visited[r][c] = 1;
            uzunluk[i]++;
        }
    }

    for(i=0 ; i<adet ; i++){
        if(durum[i] == 1)
            printf("%d. yol --> %d\n", (i+1), uzunluk[i]);
    }

    return 0;
}