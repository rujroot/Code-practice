#include<bits/stdc++.h>
using namespace std;

int DP[1010];

int main(){
    int n, A[1010];
   
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &A[i]);
        DP[i] = 1;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = i; j >= 1; --j){
            if(A[i] > A[j])
                DP[i] = max(DP[i], DP[j] + 1);
        }
    }

    int Max = 0;
    for(int i = 1; i <= n; ++i){
        Max = max(Max, DP[i]);
    }

    printf("%d", Max);
}