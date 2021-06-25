#include<bits/stdc++.h>
using namespace std;
int indegree[100010];
bool visited[100010];
vector<int> g[100010], level[10010];
int main(){
    int N, K, T; scanf("%d %d %d", &N, &K, &T);
    for(int i = 1; i <= N; ++i){
        int L, P; scanf("%d %d", &L, &P);
        //level[L].push_back(i);
        for(int j = 0; j < P; ++j){
            int q; scanf("%d", &q);
            g[L].push_back(i);
            //indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> topo;
    for(int i = 1; i <= N; ++i){
        if(!indegree[i]) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : g[u]){
            indegree[v]--;
            if(!indegree[v]) q.push(v);
        }
    }
    for(auto x : topo) printf("%d ", x);
    if(topo.size() != N){
        printf("-1");
        return 0;
    }
    for(int i = 0; i < T; ++i) visited[topo[i]] = true;
    for(int i = 1; i <= K; ++i){
        for(int j = 0; j < level[i].size(); ++j){
            //printf("%d ", level[i][j]);
            if(!visited[level[i][j]]){
                if(j == 0) printf("%d", i - 1);
                else printf("%d", i);
                return 0;
            }
        }
    }
    printf("%d", K);
    return 0;
}
