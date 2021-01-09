#include<bits/stdc++.h>
using namespace std;

int DP[2021][2021], A[2021][2021], n, m;

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int x; scanf("%d", &x);
            A[i][j] = x;
        }
    }

    for(int i = 1; i <= n; ++i){
        if(i % 2 == 0){
            for(int j = m; j >= 1; --j){
                if(A[i][j] == -1)
                    continue;
                DP[i][j] = max(DP[i - 1][j] , DP[i][j + 1]) + A[i][j];
            }
        }
        else{
            for(int j = 1; j <= m; ++j){
                if(A[i][j] == -1)
                    continue;
                DP[i][j] = max(DP[i - 1][j] , DP[i][j - 1]) + A[i][j];
            }
        }
    }

    int Max = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m ; ++j){
            Max = max(Max , DP[i][j]);
        }
    }

    printf("%d", Max);
    return 0;

}
