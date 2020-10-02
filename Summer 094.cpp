#include<bits/stdc++.h>
using namespace std;

int dp[1010], a[1010], n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < i; ++j){
            if(a[j] >= a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int Max = 0;
    for(int i = 0;i <= n; ++i){
        Max = max(Max , dp[i]);
    }
    printf("%d", n - Max);
}
