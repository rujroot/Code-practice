#include<bits/stdc++.h>
using namespace std;

bool DP[110][50010];

int main(){
    int n, A[110];
    scanf("%d", &n);

    int sum = 0;
    for(int i = 1; i <= n; ++i){
        int x; scanf("%d", &x);
        A[i] = x;
        DP[i][0] = true;
        sum += x;
    }
    DP[0][0] = true;
    
    if(sum % 2 != 0){
        printf("No");
        return 0;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= sum / 2; ++j){
            DP[i][j] = DP[i - 1][j] or DP[i - 1][j - A[i]];
        }
    }

    if(DP[n][sum / 2])
        printf("Yes");
    else
        printf("No");
    
    return 0;
    
}
