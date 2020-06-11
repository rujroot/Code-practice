/*  1084 : riddle
    ST : 10.46 11/6/63 ED : 0.45 12/6/63
    O(n log i)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
long long int x,y,k,ans=0,zero,Plus = 0,tmp = 5;
long long int Find(long long n,long long i){
    if(n / i == 0){
        tmp = i;
        return 0;
    }
    return n/i + Find(n,i*5);
}
int main()
{
    scanf("%lld %lld %lld",&x,&y,&k);
    zero = Find(x,5);
    for(int i=x;i<=y;++i){
        if(i % 5 == 0 and i != x){
            Plus++;
        }
        if(i % 25 == 0 and i != x){
            zero = Find(i,5);
            Plus = 0;
        }
        ans += zero + Plus;
        ans %= k;
    }
    printf("%lld",ans);
    return 0;
}

