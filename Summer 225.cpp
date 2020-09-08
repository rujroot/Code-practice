#include <bits/stdc++.h>
using namespace std;

long long DP[30][30];

int main()
{
    int T;
    scanf("%d", &T);
    DP[1][1] = 1;
    for (int i = 2; i <= 25; ++i){
        for(int j = 1; j <= i; ++j){
            if(j == 1){
                DP[i][j] = 1;
            }
            else if(j == i){
                DP[i][j] = 1;
            }
            else{
                DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j] * j;
            }
        }
    }
    for(int i = 0; i < T; ++i){
        int K, N; scanf("%d %d", &K, &N);
        printf("%lld\n", DP[K][N]);
    }

    return 0;
}
