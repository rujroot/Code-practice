#include<bits/stdc++.h>
using namespace std;

bool DP[110][110][2000];

int main(){
    int n, A[110], sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int x; scanf("%d", &x);
        A[i] = x;
        sum += x;
    }

    if(sum % 3 != 0){
        printf("noob");
        return 0;
    }
    
    for(int i = 0; i <= n ; ++i){
        for(int j = 0; j <= n; ++j){
            DP[i][j][0] = true;
        }
    }

    DP[0][0][0] = true;

    for(int i = 1; i <= n; ++i){
         for(int j = i; j <= n; ++j){
            for(int k = 1; k <= sum / 3; ++k){
                if(k - A[j] >= 0)
                    DP[i][j][k] = DP[i][j - 1][k] or DP[i][j - 1][k - A[j]];
                else
                    DP[i][j][k] = DP[i][j - 1][k];
            }
        }
    }

    for(int i = 1; i < n; ++i){
        if(DP[1][i][sum / 3] and DP[i + 1][n][sum / 3]){
            if(sum - 2 * (sum / 3) == sum / 3){
                printf("mission complete");
                return 0;
            }
        }
    }

    printf("noob");
    return 0;

}
