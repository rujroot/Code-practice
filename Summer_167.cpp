#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;

vector<pair<int, int>> g[10010];
vector<int> Max(10010, -1);

int main(){
    int N, M, S, T, P; scanf("%d %d %d %d %d", &N, &M, &S, &T, &P);
    for(int i = 0; i < M; ++i){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
    }

    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    pq.emplace(0, 0, S);
    Max[S] = 0;
    while(!pq.empty()){
        int u = get<2>(pq.top()), Maxw = get<1>(pq.top()), Sum = get<0>(pq.top());
        pq.pop();
        for(auto vw : g[u]){
            int v = vw.first, w = vw.second;
            if((Max[v] < Maxw or Max[v] < w) and Sum + w < P){
                Max[v] = max({w, Max[v], Maxw});
                pq.emplace(Sum + w, Max[v], v);
            }
        }
    }
    printf("%d", Max[T]);
}
