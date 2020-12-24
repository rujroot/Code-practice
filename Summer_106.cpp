#include<bits/stdc++.h>
using namespace std;

int DP[1010][1010], v[1010], N, K;

int main(){
    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; ++i){
        int x; scanf("%d", &x);
        v[i] = x;
    }

    for(int i = 0; i <= K; ++i){
        DP[i][0] = 0;
    }
    for(int i = 1; i <= N; ++i){
        DP[0][i] = 1;
    }
    DP[0][0] = 1;

    for(int i = 1; i <= K; ++i){
        for(int j = 1; j <= N; ++j){
            if(i - v[j] < 0 and j - 1 < 0){
                DP[i][j] = 0;
            }
            else if(i - v[j] < 0){
                DP[i][j] += DP[i][j-1] % 1000000007;

            }
            else if(j - 1 < 0){
                DP[i][j] += DP[i - v[j]][j] % 1000000007;
            }
            else{
                DP[i][j] += (DP[i][j - 1] + DP[i - v[j]][j]) % 1000000007;
            }
        }
    }
    printf("%d", DP[K][N]);

}
