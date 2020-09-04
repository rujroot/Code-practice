#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int Q,a,b;
    scanf("%lld",&Q);
    for(int i=0;i<Q;++i){
        scanf("%lld %lld",&a,&b);
        if(b >= a)
            printf("%lld\n",((b+1)*(b)/2) - ((a)*(a-1)/2));
        else
            printf("0\n");
    }
    return 0;
}
