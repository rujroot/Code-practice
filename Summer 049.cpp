#include <bits/stdc++.h>
using namespace std;

long long int a[1000100], qs[1000100];

int main()
{
    long long int n, T, L, R, V;
    scanf("%lld %lld", &n, &T);
    for (int i = 0; i < n; ++i){
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < T; ++i){
        scanf("%lld %lld %lld", &L, &R, &V);
        qs[L - 1] += V;
        qs[R] -= V;
    }

    for (int i = 1; i <= n; ++i){
       qs[i] += qs[i - 1];
    }

    for (int i = 0; i < n; ++i){
        printf("%lld ", a[i] + qs[i]);
    }
}
