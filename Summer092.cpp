#include<bits/stdc++.h>
using namespace std;

long long a[1010][1010];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
           scanf("%lld", &a[i][j]);
        }
    }

    for(int i = 1; i <= m; ++i){
        a[n][i] = 5000 - a[n][i];

        if(a[n][i] <= 0)
            a[n][i] = -2e9;

        a[n][i] += 500;

    }
    for(int i = n - 1; i >= 0; --i){
        for(int j = 1; j <= m; ++j){
            long long power;
            if(j == 1)
                power = max( a[i + 1][j], a[i + 1][j + 1]);
            else if(j == m)
                power =  max( a[i + 1][j], a[i + 1][j - 1]);
            else
                power = max(max(a[i + 1][j + 1], a[i + 1][j - 1]) , a[i + 1][j]);

            if(power - a[i][j] < 0)
                a[i][j] = -2e9;
            else
                a[i][j] = power - a[i][j] + 500;
        }
    }

    long long Max = -2e9;
    for(int i = 1; i <= m; ++i){
        Max = max(Max, a[1][i]);
    }
    long long Ans = abs(Max - 5000 - 500 * n);

    if(Max < 0)
        printf("-1");
    else
        printf("%lld",Ans);

}
