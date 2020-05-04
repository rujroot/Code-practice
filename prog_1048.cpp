/*  1048 : Find the Distant
    ST : 17.15 4/5/2563 ED : 18.11 4/5/2563
    0(n^2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int k,n,HD = 0,xr,num1,num2;
    scanf("%lld %lld",&k,&n);
    for(int i=0;i<n;++i){
        num1 = i;
        num2 = i+1;
        xr = num1^num2;
        for(int j=0;j<k;++j){
            if((xr & (1 << j)) != 0){
                HD++;
            }
        }
    }
    printf("%lld",HD);
    return 0;
}

