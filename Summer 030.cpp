#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int T,a,b,m;
    scanf("%lld",&T);
    for(int i=0;i<T;++i){
        scanf("%lld %lld %lld",&a,&b,&m);
        printf("%d\n",( ( b / m ) - (a-1) / m ) );
    }
    return 0;
}
