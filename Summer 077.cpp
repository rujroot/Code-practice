#include <bits/stdc++.h>

using namespace std;

long long arr[10000];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%lld", &arr[i]);
    }
    long long curr = arr[0], Max = arr[0];
    for (int i = 1;i < n; ++i){
        curr = max(arr[i], curr + arr[i]);
        Max = max(Max, curr);
    }
    printf("%lld",Max);
    return 0;
}
