#include<bits/stdc++.h>
using namespace std;

int a[100][100];
unsigned long long DP[110][110][10100];

int main(){
    int n, m, t;
    scanf("%d %d %d" ,&n , &m, &t);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int x; scanf("%d", &x);
            a[i][j] = x;
        }
    }

    DP[1][1][a[1][1]] = 1;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            for(int k = 1; k <= 10000; ++k){
                if(k - a[i][j] < 0)
                    continue;
                else if(i - 1 <= 0 and j - 1 <= 0)
                    continue;
                else if(j - 1 <= 0)
                    DP[i][j][k] = DP[i - 1][j][k - a[i][j]];
                else if(i - 1 <= 0)
                    DP[i][j][k] = DP[i][j - 1][k - a[i][j]];
                else
                     DP[i][j][k] = DP[i][j - 1][k - a[i][j]] + DP[i - 1][j][k - a[i][j]];
            }
        }
    }

    for(int i = 0; i < t; ++i){
        int Q; scanf("%d", &Q);
        printf("%lu\n",DP[n][m][Q]);
    }
    
    return 0;

}