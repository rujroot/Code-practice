
#include <bits/stdc++.h>
using namespace std;
int tarang[20][20];
bool trc[110];
int main()
{
    int n,sum = 0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&tarang[i][j]);
            if(i == 0){
                sum += tarang[i][j];
            }
            if(!trc[tarang[i][j]]){
                trc[tarang[i][j]] = true;
            }else{
                printf("No");
                return 0;
            }
        }

    }
  //  printf("%d",sum);
    for(int i=0;i<n;++i){
        int sumca = 0,sumro = 0;
        for(int j=0;j<n;++j){
            sumca += tarang[i][j];
            sumro += tarang[j][i];
        }
        if(sumca != sum or sumro != sum){
            printf("No");
            return 0;
        }
    }
    int sumRL = 0,sumLR = 0;
    for(int i=0;i<n;++i){

        sumRL += tarang[i][i];
        sumLR += tarang[n-i-1][n-i-1];
    }
    if(sumRL != sum or sumLR != sum){
            printf("No");
            return 0;
        }
    printf("Yes");
    return 0;
}
