#include<bits/stdc++.h>
using namespace std;

bool DP[110][50010];

int main(){
    int n, A[110], sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int x; scanf("%d", &x);
        A[i] = x;
        sum += x;
        DP[i][0] = true;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= sum / 2; ++j){
            DP[i][j] = DP[i - 1][j] or DP[i - 1][j - A[i]];
        }
    }

    for(int i = sum / 2; i >= 0; --i){
        if(DP[n][i]){
            printf("%d",abs(2 * i - sum));
            return 0;
        }
    }
}
