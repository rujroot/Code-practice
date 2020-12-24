#include<bits/stdc++.h>
using namespace std;

int DP[1010][1010];
int N, K;
vector<int> v;

int main(){
    scanf("%d %d", &N, &K);
    v.push_back(0);
    for(int i = 0; i < N; ++i){
        int x; scanf("%d", &x);
        v.push_back(x);
    }

    for(int i = 0; i <= K; ++i){
        DP[i][0] = 0;
    }
    for(int i = 1; i <= N; ++i){
        DP[0][i] = 1;
    }
    DP[0][0] = 1;

    for(int i = 1; i <= K; ++i){
        for(int j = 1; j < v.size(); ++j){
            if(i - v[j] < 0 and j - 1 < 0){
                DP[i][j] = 0;
            }
            else if(i - v[j] < 0){
                DP[i][j] += DP[i][j-1] % 1000000007;

            }
            else if(j - 1 < 0){
                DP[i][j] += DP[i - v[j]][j] % 1000000007;
            }
            else{
                DP[i][j] += (DP[i][j - 1] + DP[i - v[j]][j]) % 1000000007;
            }
        }
    }
    printf("%d", DP[K][N]);

}
