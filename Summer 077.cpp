#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    long long curr = 0, Max = 0, num;

    for(int i = 0; i < n; ++i){
        scanf("%lld", &num);
        curr = max(num, curr + num);
        Max = max(Max, curr);
    }

    printf("%lld",Max);
    return 0;
}
