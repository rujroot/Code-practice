#include<bits/stdc++.h>
using namespace std;

long long DP[2021], A[2020];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        long long x; scanf("%lld", &x);
        A[i] = x;
        DP[i] = x;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = i; j >= 1; --j){
            if(A[i] > A[j])
                DP[i] = max(DP[i], A[i] + DP[j]);
        }
    }


    long long Max = -9e18;
    for(int i = 1; i <= n; ++i){
        Max = max(Max, DP[i]);
    }
    printf("%lld", Max);
    return 0;    
}