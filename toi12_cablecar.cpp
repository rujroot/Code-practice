#include<bits/stdc++.h>
#define n 2510
using namespace std;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;

int p[n];
bool visited[n];
vector<pii> g[n];
vector<tiii> edge;

int Find(int u){
    if(u != p[u]) return p[u] = Find(p[u]);
    return u;
}

int main(){
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < n; ++i) p[i] = i;
    for(int i = 0; i < M; ++i){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        edge.emplace_back(w, u, v);
    }

    sort(edge.begin(), edge.end(), greater<tiii>());

    int s, d; scanf("%d %d", &s, &d);
    long long c; scanf("%lld", &c);

    for(int i= 0; i < edge.size(); ++i){
        int w = get<0>(edge[i]), u = get<1>(edge[i]), v= get<2>(edge[i]);
        int pu = Find(u), pv = Find(v);
        if(pu != pv){
            p[pv] = pu;
            g[u].push_back({w, v});
            g[v].push_back({w, u});
        }
    }

    queue<pii> q;
    q.push({2e9, s});
    while(!q.empty()){
        int minw = q.front().first, u = q.front().second;
        q.pop();

        if(u == d){
            printf("%lld", (c + minw - 2) / (long long)(minw - 1));
            return 0;
        }

        for(auto wv : g[u]){
            int w = wv.first, v = wv.second;
            if(!visited[v]){
                visited[v] = true;
                q.push({min(minw, w), v});
            }
        }
    }
}
