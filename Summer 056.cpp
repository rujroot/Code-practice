#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    long long int p[110][110];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%lld",& p[i][j]);
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            printf("%lld ", p[j][i]);
        }
        printf("\n");
    }
    return 0;
}
