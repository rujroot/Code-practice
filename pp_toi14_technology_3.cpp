#include<bits/stdc++.h>
using namespace std;

int color[100010], num;
bool cycle;
vector<int> g[100010], level[100010];

bool dfs(int u){
    if(color[u] == 1) return true;
    if(color[u] == 2) return false;

    color[u] = 1;

    for(auto v : g[u]){
        if(dfs(v)) return true;
    }

    num++;
    color[u] = 2;
    return false;

}

int main(){
    int N, K, T;
    scanf("%d %d %d", &N, &K, &T);
    for(int i = 1; i <= N; ++i){
        int L, P; scanf("%d %d", &L, &P);
        level[L].push_back(i);
        for(int j = 1; j <= P; ++j){
            int q; scanf("%d", &q);
            g[i].push_back(q);
        }
    }

    int Ans = -1;
    for(int i = 1; i <= K; ++i){
        for(auto x : level[i]){
            if(dfs(x)) cycle = true;
            if(num > T) break;
        }
        if(num > T or cycle) break;
        Ans = i;
    }
    printf("%d", Ans);
    return 0;
}
