#include<bits/stdc++.h>
using namespace std;

long long DP[2021], A, m, arr[2021];

int main(){
    scanf("%d %d", &A, &m);

    for(int i = 1; i <= m; ++i){
        int x; scanf("%d", &x);
        arr[i] = x;
        
    }

    for(int i = 1; i <= A; ++i)
        DP[i] = -9e18;
        
    for(int i = 1; i <= A; ++i){
        for(int j = 1; j <= m; ++j){
            if(i - j >= 0)
                DP[i] = max(DP[i], DP[i - j] + arr[j]);
        }
    }

    printf("%lld", DP[A]);
}