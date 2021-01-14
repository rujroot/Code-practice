#include<bits/stdc++.h>
using namespace std;

int DP1[3010], DP2[3010];

int main(){
    int n, A[3010];
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int x; scanf("%d", &x);
        A[i] = x;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i; j >= 1; --j){
            if(A[i] < A[j])
                DP1[i] = max(DP1[i], DP2[j] + 1);
            if(A[i] > A[j])
                DP2[i] = max(DP2[i], DP1[j] + 1);       
        }
    }

    printf("%d", max(DP1[n] + 1, DP2[n] + 1));
    return 0;

}