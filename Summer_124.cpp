//ST : 18.31 25/1/2564
#include<bits/stdc++.h>
using namespace std;

long long DP[310][310];
int A[310];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &A[i]);
    }

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            DP[i][j] = 9e18;
        }
        DP[i][i] = A[i];
    }

    for(int l = 0; l <= n; ++l){
        for(int i = 1; i <= n; ++i){
            if(i + l > n)
                break;
            for(int j = i; j <= i + l; ++j){
                for(int m = i; m <= j; ++m){
                    if(m - 1 < i)
                        DP[i][j] = min(DP[i][j], DP[m + 1][j] + A[m]);
                    if(m + 1 > j)
                        DP[i][j] = min(DP[i][j], DP[i][m - 1] + A[m]);
                    else
                        DP[i][j] = min(DP[i][j], max(DP[i][m - 1], DP[m + 1][j]) + A[m]);

                    
                }
            }
        }
    }

   /*for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            printf("%lld ", DP[i][j]);
        }printf("\n");
    }*/
    printf("%lld",DP[1][n]);
}
