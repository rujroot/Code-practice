#include <bits/stdc++.h>
using namespace std;
long long int k, num, sum, sum1;
long long int BS(long long int l, long long int r, long long int x){
    while (l <= r){
        long long int m = l + (r - l) / 2;
        sum = ((m * m * m) + (5 * m)) / 6;
        sum1 = (((m + 1) * (m + 1) * (m + 1)) + (5 * (m + 1))) / 6;
        if(sum < x and sum1 >= x)
            return m;
        if(sum < x)
            l = m + 1;
        else
            r = m - 1;
    }
}
int main()
{

    scanf("%lld", &k);
    long long int Q;
    for (int i = 0; i < k; ++i){
        scanf("%lld", &Q);
        long long Ans = BS(-2e6,2e6,Q);
        printf("%lld\n",Ans + 1 );
    }
    return 0;
}
