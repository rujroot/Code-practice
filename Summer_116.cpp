#include<bits/stdc++.h>
using namespace std;

long long DP[1000010], A[1000010];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){
        long long x; scanf("%lld", &x);
        A[i] = x;
    }

    DP[1] = max(DP[1],A[1]);

    for(int i = 2; i <= n; ++i){
        DP[i] = max(DP[i - 2] + A[i], DP[i - 1]);
    }

    printf("%lld", DP[n]);


}