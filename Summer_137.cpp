#include<bits/stdc++.h>
using namespace std;
int n, m, A[20][20];
long long Ans = 9e18;

long long Mario(long long sum, int i, int j){
    if(j == 0 or j == m + 1)
        return 0;

    if(i == n + 1){
        Ans = min(Ans,sum);
        return 0;
    }

    sum += A[i][j];
    Mario(sum, i + 1, j);
    Mario(sum, i + 1, j - 1);
    Mario(sum, i + 1, j + 1);
}

int main(){
   scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%d", &A[i][j]);
        }
    }

    for(int j = 1; j <= m; ++j){
        Mario(0, 1, j);
    }

    printf("%lld", Ans);
    return 0;
}