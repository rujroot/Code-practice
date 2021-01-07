#define mod 1000000007
#include<bits/stdc++.h>
using namespace std;

int DP[2021][2021];

int main(){
    char s1[2021], s2[2021];
    scanf("%s %s", s1 + 1, s2 + 1);
    int Ls1 = strlen(s1 + 1), Ls2 = strlen(s2 + 1);
    
    for(int i = 1; i <= Ls1; ++i){
        if(s1[i] == s2[1])
            DP[i][1] = DP[i - 1][1] + 1 % mod;
        else
            DP[i][1] = DP[i - 1][1] % mod;
    }

    for(int i = 1; i <= Ls1; ++i){
        for(int j = 2; j <= min(i, Ls2); ++j){
            if(s1[i] == s2[j])
                DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % mod;
            else
                DP[i][j] = DP[i - 1][j];
        }
    }

    /*for(int i = 1; i <= Ls1; ++i){
        for(int j = 1; j <= Ls2; ++j){
            printf("%d ", DP[i][j]);
        }printf("\n");
    }*/

    printf("%d", DP[Ls1][Ls2]);
}