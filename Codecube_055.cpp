#include<bits/stdc++.h>
using namespace std;

long long DP[1010][1010];

int main(){
    DP[1][1] = 1;
    for(int i = 2; i <= 1000; ++i){
        for(int j = 1; j <= 1000; ++j){
            DP[i][j] = (DP[i - 1][j] * j + DP[i - 1][j - 1]) % 9871;
        }
    }

    int Q; scanf("%d", &Q);
    for(int i = 1; i <= Q; ++i){
        int N, K; scanf("%d %d", &N, &K);
        printf("%lld\n", DP[N][K]);
    }
    return 0;
}