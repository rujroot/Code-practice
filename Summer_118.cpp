#define mod 2017
#include<bits/stdc++.h>
using namespace std;

int DP[100010][30], A[30];

int main(){
    int n,K;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int x; scanf("%d", &x);
        A[i] = x;
    }
    
    scanf("%d", &K);

    for(int i = 0; i <= K; ++i){
        DP[i][0] = 0;
    }
    for(int i = 1; i <= n; ++i){
        DP[0][i] = 1;
    }
    DP[0][0] = 1;

    for(int i = 1; i <= K; ++i){
        for(int j = 1; j <= n ; ++j){
            if(i - A[j] < 0 and j - 1 < 0){
                DP[i][j] = 0;
            }
            else if(i - A[j] < 0){
                DP[i][j] += DP[i][j - 1] % mod;

            }
            else if(j - 1 < 0){
                DP[i][j] += DP[i - A[j]][j] % mod;
            }
            else
                DP[i][j] = (DP[i][j - 1] + DP[i - A[j]][j]) % mod;
        }
    }

    printf("%d", DP[K][n]);
}