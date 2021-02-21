#include<bits/stdc++.h>
using namespace std;

int DP[210][1100];
pair<int, int> p[210];

void setzero(){
    for(int i = 0; i <= 201; ++i){
        for(int j = 0; j <= 1001; ++j){
            DP[i][j] = 0;
        }
    }

    for(int i = 0; i <= 201; ++i){
        p[i].first = 0, p[i].second = 0;
    }
}

int main(){
    int t, c ,n;
    scanf("%d",&t);
    for(int q = 1; q <= t; ++q){
        scanf("%d %d", &c, &n);
        setzero();
        for(int i = 1; i <= n; ++i){
            scanf("%d %d", &p[i].first, &p[i].second);
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= c; ++j){
                if(j - p[i].first < 0)
                    DP[i][j] = DP[i - 1][j];
                else
                    DP[i][j] = max( p[i].second + DP[i - 1][j - p[i].first], DP[i - 1][j]);
            }
        }
        printf("%d\n", DP[n][c]);
    }
    

    
}