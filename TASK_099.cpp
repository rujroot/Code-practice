#include<bits/stdc++.h>
using namespace std;

long long DP[220][220];
int F[220], B[220];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int x, y; scanf("%d %d", &x ,&y);
        F[i] = x;
        B[i] = y;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            DP[i][j] = 2e9;
        }
        DP[i][i] = 0;
    }

    for(int l = 0; l <= n ; ++l){
        for(int i = 1; i <= n; ++i){
            if(i + l > n)
                break;
            for(int j = i; j <= i + l; ++j){
                for(int d = 1; d <= (j - i); ++d){
                    DP[i][j] = min({DP[i][j], F[i] * B[i + d - 1] * B[j] + DP[i][i + d - 1] + DP[i + d][j], F[i] * F[j - d + 1] * B[j] + DP[i][j - d] + DP[j - d + 1][j]});
                }
                /*if((j - i + 1) % 2 == 0){
                    int mid = i + (j - i)/2;
                    DP[i][j] = min(DP[i][j], F[i] * B[mid] * B[j] + DP[i][mid] + DP[mid + 1][j]);
                }*/
                    
            }
        }
    }

    printf("%lld", DP[1][n]);
}
