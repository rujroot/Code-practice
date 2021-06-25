#include<bits/stdc++.h>
#define n 2510
using namespace std;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;

vector<int> dist(n, -2e9);
bool visited[n], visited2[n];
vector<pii> g[n], gans[n];

int main(){
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int s, d; scanf("%d %d", &s, &d);
    long long p; scanf("%lld", &p);

    priority_queue<tiii> pq;
    dist[s] = 0;
    pq.emplace(dist[s], s, s);
    while(!pq.empty()){
        int u = get<1>(pq.top()), p = get<2>(pq.top()), d = get<0>(pq.top());
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        if(u != p)
        {
            gans[p].push_back({d, u});
            gans[u].push_back({d, p});
        }
        for(pii vw : g[u]){
            int v = vw.first, w = vw.second;
            if(!visited[v] and w > dist[v]){
                dist[v] = w;
                pq.emplace(dist[v], v, u);
            }
        }
    }

    queue<pii> q;
    q.push({2e9, s});


}
