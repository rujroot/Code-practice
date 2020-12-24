#include<bits/stdc++.h>
using namespace std;

int DP[1010][1010];
int N, K;
vector<int> v;

int Slove(int i, int j){
    if(i == 0 and j == 0)
        return 1;
    if(i == 0)
        return 1;
    if(j < 0 or i < 0)
        return 0;
    if(DP[i][j])
        return DP[i][j];
    DP[i][j] += (Slove(i, j - 1) + Slove(i - v[j], j)) % 1000000007;
;
    return DP[i][j]; 
}

int main(){
    scanf("%d %d", &N, &K);
    
    for(int i = 0; i < N; ++i){
        int x; scanf("%d", &x);
        v.push_back(x);
    }

    printf("%d", Slove(K, N - 1));
}
