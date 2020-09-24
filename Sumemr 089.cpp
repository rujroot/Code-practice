#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long num;
    scanf("%d", &n);
    scanf("%lld", &num);
    long long curr = num, Max = num;
    for(int i = 1; i < n; ++i){
        scanf("%lld", &num);
        curr = max(num , curr + num);
        Max = max(Max , curr);
    }
    printf("%lld", Max);
    return 0;
}
