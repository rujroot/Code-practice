#include<bits/stdc++.h>
using namespace std;

int L1, L2, n;
char S1[2021],S2[2021];
bool DP[2021][2021];

bool Solve(){

    for(int i = 1; i <= L1; ++i){
        for(int j = 1; j <= L2; ++j){
            if(i == 1 and j == 1 and S2[j] == '$')
                DP[1][1] = true;
            else if(S2[j] == '-' or S1[i] == S2[j])
                DP[i][j] = DP[i - 1][j - 1];
            else if(S2[j] != S1[i] and S2[j] != '$')
                DP[i][j] = DP[i][j - 1] and DP[i - 1][j];
            else
                DP[i][j] = DP[i - 1][j] or DP[i][j - 1];
        }
    }
    return DP[L1][L2];
}


int main(){
    //printf("%d %d", 'a', 'z');
    scanf("%s", S1 + 1);
    scanf("%d", &n);
    L1 = strlen(S1 + 1);

    
    DP[0][0] = true;

    for(int i = 1;i <= n; ++i){
        scanf("%s", S2 + 1);
        L2 = strlen(S2 + 1);

        if(Solve())
            printf("success\n");
        else
            printf("fail\n");

        /*for(int i = 1; i <= L1; ++i){
             for(int j = 1; j <= L2; ++j){
                printf("%d ", DP[i][j]);
             }printf("\n");
        }*/

        for(int i = 0; i <= 2001; ++i){
             for(int j = 0; j <= 2001; ++j){
                DP[i][j] = false;
             }
        }
        DP[0][0] = true;
    }
}
