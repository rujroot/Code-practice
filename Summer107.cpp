#include<bits/stdc++.h>
using namespace std;

int DP[70][70][70][70];
bool visited[70][70][70][70];
char ss1[70], ss2[70], ss3[70], ss4[70];
string s1,s2,s3,s4;

/*int Solve(int i, int j, int k, int l){
    if(i == -1 or j == -1 or k == -1 or l == -1)
        return 0;
    if(visited[i][j][k][l])
        return DP[i][j][k][l];

   visited[i][j][k][l] = true;
    if(s1[i] == s2[j] and s2[j] == s3[k] and s3[k] == s4[l])
        return DP[i][j][k][l] = 1 + Solve(i - 1, j - 1, k - 1, l - 1);
    return DP[i][j][k][l] = max(max( Solve(i - 1, j, k, l ), Solve(i , j - 1, k, l )) , max( Solve(i , j, k - 1, l ), Solve(i , j, k, l - 1)));
}*/

int main(){
    cin >> s1 >> s2 >> s3 >> s4;
    int Si1 = s1.size(), Si2 = s2.size(), Si3 = s3.size(), Si4 = s4.size();
    
    //printf("%d",Solve(Si1 - 1, Si2 - 1, Si3 - 1, Si4 - 1));
    for(int i = 0; i < Si1; ++i){
        ss1[i + 1] = s1[i];
    }
    for(int i = 0; i < Si2; ++i){
        ss2[i + 1] = s2[i];
    }
    for(int i = 0; i < Si3; ++i){
        ss3[i + 1] = s3[i];
    }
    for(int i = 0; i < Si4; ++i){
        ss4[i + 1] = s4[i];
       
    }

    for(int i = 1; i <= Si1; ++i){
        for(int j = 1; j <= Si2; ++j){
            for(int k = 1; k <= Si3; ++k){
                for(int l = 1; l <= Si4; ++l){           
                    if(ss1[i] == ss2[j] and ss2[j] == ss3[k] and ss3[k] == ss4[l])
                        DP[i][j][k][l] = 1 + DP[i - 1][j - 1][k - 1][l - 1];
                    else
                        DP[i][j][k][l] = max(max(DP[i - 1][j][k][l], DP[i][j - 1][k][l]), max(DP[i][j][k - 1][l] ,DP[i][j][k][l - 1] ));
                }
            }
        }
    }
    printf("%d", DP[Si1][Si2][Si3][Si4]);
}