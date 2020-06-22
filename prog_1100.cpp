/*  1100 : Codes
    ST : 22.20
    Read : 22.20 - 23.02
    Rest : 0.52 21/6/63 - 16.50 22/6/63
    End : 17.18 22/6/63
    O(n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
long long int N,x,digit[5],C1[5][15],C2[5][15][15],C3[1001],ans;
int main()
{
    scanf("%lld",&N);
    for(int i=0;i<N;++i){
        scanf("%lld",&x);
        C3[x]++;
        for(int j=3;j>=1;--j){
            C1[j][x%10]++;
            digit[j] = x%10;
            x = x/10;
        }
        C2[1][digit[1]][digit[2]]++;
        C2[2][digit[1]][digit[3]]++;
        C2[3][digit[2]][digit[3]]++;
    }
    for(int i=1;i<=3;++i){
        for(int j=0;j<10;++j){
            if(C1[i][j] == 0)
                continue;
            ans += C1[i][j]*(C1[i][j]-1)/2;
        }
    }
    for(int i=1;i<=3;++i){
        for(int j=0;j<10;++j){
            for(int k=0;k<10;++k){
                if(C2[i][j][k] == 0)
                    continue;
                ans -= C2[i][j][k]*(C2[i][j][k]-1)/2;
            }
        }
    }
    for(int i=0;i<1000;++i){
        if(C3[i] == 0)
            continue;
        ans += C3[i]*(C3[i]-1)/2;
    }
    printf("%lld",ans);
    return 0;
}

