#include<bits/stdc++.h>
using namespace std;

long long Dp[1000010], Num[5];


int main(){
    int n;
    scanf("%d", &n);
    Num[0] = 1;
    Num[1] = 3;
    Num[2] = 4;
    Dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 3; ++j){
            if(i - Num[j] >= 0)
                Dp[i] += Dp[i - Num[j]]; 
            Dp[i] %= 1000000007;
        }
    }
    printf("%lld", Dp[n]);
}