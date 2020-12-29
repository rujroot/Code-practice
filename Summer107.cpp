#include<bits/stdc++.h>
using namespace std;

int DP[70][70][70][70];
char ss1[70], ss2[70], ss3[70], ss4[70];

int main(){
    scanf("%s %s %s %s", ss1 + 1, ss2 + 1, ss3 + 1, ss4 + 1);
    int Si1 = strlen(ss1 + 1), Si2 = strlen(ss2 + 1), Si3 = strlen(ss3 + 1), Si4 = strlen(ss4 + 1);
    
    for(int i = 1; i <= Si1; ++i){
        for(int j = 1; j <= Si2; ++j){
            for(int k = 1; k <= Si3; ++k){
                for(int l = 1; l <= Si4; ++l){           
                    if(ss1[i] == ss2[j] and ss2[j] == ss3[k] and ss3[k] == ss4[l])
                        DP[i][j][k][l] = 1 + DP[i - 1][j - 1][k - 1][l - 1];
                    else
                        DP[i][j][k][l] = max({DP[i - 1][j][k][l], DP[i][j - 1][k][l], DP[i][j][k - 1][l] , DP[i][j][k][l - 1] });
                }
            }
        }
    }

    printf("%d", DP[Si1][Si2][Si3][Si4]);
    return 0;
}
