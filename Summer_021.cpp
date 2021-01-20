#include<bits/stdc++.h>
using namespace std;

int n, k;
long long DP[20][100100];
pair<int, int> p[20];

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i){
        int x,y; scanf("%d %d", &x , &y);
        p[i].first = x;
        p[i].second = y;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= k; ++j){
            if(j - p[i].first >= 0)
                DP[i][j] = max(DP[i - 1][j - p[i].first] + p[i].second , DP[i - 1][j]);
            else
                DP[i][j] = DP[i - 1][j];
            
        }
    }

    printf("%lld",DP[n][k]);
}