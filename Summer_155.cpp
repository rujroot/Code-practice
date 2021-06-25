#include<bits/stdc++.h>
#define N 100010
using namespace std;
typedef tuple<int, int, int> tiii;

int n, m, p[N], rnk[N];
vector<tiii> v;

int Find(int u){
    if(p[u] != u) return Find(p[u]);
    return u;
}

void mg(int pu, int pv){
    if(rnk[pu] > rnk[pv]){
        rnk[pu] += rnk[pv];
        p[pv] = pu;
    }else{
        rnk[pv] += rnk[pu];
        p[pu] = pv;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i){
        int a, b; scanf("%d %d", &a, &b);
        v.emplace_back(-i, a, b);
    }
    for(int i = 0; i < N; ++i){
        rnk[i] = 1;
        p[i] = i;
    }
    sort(v.begin(), v.end());

    int Min = 2e9;
    for(auto wuv : v){
        int w = -get<0>(wuv), u = get<1>(wuv), v = get<2>(wuv);
        int pu = Find(u), pv = Find(v);
        if(pu != pv){
            Min = min(Min, w);
            mg(pu, pv);
        }
    }
    printf("%d", Min - 1);

}
