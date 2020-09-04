#include <bits/stdc++.h>
using namespace std;
long long int n,m,x,y,arr[100005];
int main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&x);
        arr[i] = arr[i-1] + x;
    }
    for(int i=0;i<m;++i){
        scanf("%lld %lld",&x,&y);
        printf("%lld\n",arr[y] - arr[x-1]);
    }
    return 0;
}
