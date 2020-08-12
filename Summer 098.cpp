#include <bits/stdc++.h>
using namespace std;
int dp[3501][3501];
int main()
{
    int N,M,Max = 0;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            scanf("%d",&dp[i][j]);
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(dp[i][j] == 0)
                continue;
            dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;

        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            Max = max(Max,dp[i][j]);
        }
    }
    printf("%d",Max);
    return 0;
}
