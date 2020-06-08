/*  1082 :overtree
    ST : 11.25 8/6/63 ED : 22.18 8/6/63
    O(n log n)
    Rujroot
*/
#include<bits/stdc++.h>
using namespace std;
int N,M,x,y,z,po,u,v;
vector<tuple<int,int,int>> vec;
vector<pair<int,int>> vt;
int P[100010];
int FindSet(int e){
    while(P[e] != e){
        e = P[e];
    }
    return e;
}
void unoinset(int s,int t){
    P[t] = s;
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;++i){
        scanf("%d %d %d",&x,&y,&z);
        vec.emplace_back(z,x,y);
        P[x] = x;
        P[y] = y;
    }
    sort(vec.begin(),vec.end());
    while(vt.size() < N-1){
        //printf("%d\n",vt.size());
        u = get<1>(vec[po]);
        v = get<2>(vec[po]);
        if(FindSet(u) != FindSet(v)){
            vt.push_back({u,v});
            unoinset(FindSet(u),FindSet(v));
        }
        po++;
    }
    for(int i=0;i<vt.size();++i){
        printf("%d %d\n",vt[i].first,vt[i].second);
    }
}

