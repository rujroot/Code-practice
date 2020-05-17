/*  1063 : Logistics
    ST : 13.35 17/5/63 ED : 14.57 17/5/63
    o(n^2 + n^2 log n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[300];
int n,z,p1,p2;
char x,y;
bool visited[300],visitedT[300];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf(" %c %c",&x,&y);
        p1 = x;
        p2 = y;
        scanf(" %d",&z);
        adj[p1].push_back({p2,z});
        adj[p2].push_back({p1,z});
    }
    queue<int> togo;
    bool can = false;
    togo.push(88);
    while(!togo.empty()){
        int u = togo.front();
        togo.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        for(auto v : adj[u]){
            if(!visited[v.first]){
                if(v.first == 89){
                    can = true;
                }
                togo.push(v.first);
            }
        }
    }
    if(!can){
        printf("broken");
        return 0;
    }
    queue<int> togoT;
    togoT.push(88);
    vector<int> vs;
    double sum = 0;
    while(!togoT.empty()){
        int u = togoT.front();
        togoT.pop();
        if(visitedT[u])
            continue;
        visitedT[u] = true;
        char End;
        for(auto v : adj[u]){
            if(!visitedT[v.first]){
                End = v.first;
                vs.push_back(v.second);
                if(v.first != 89)
                    togoT.push(v.first);
            }
        }
        sort(vs.begin(),vs.end());
        if(vs.size() == 1){
            printf("%c %c %.1f\n",u,End,double(vs[0]));
            sum += double(vs[0]);
        }
        else if(vs.size() != 0){
            printf("%c %c ",u,End);
           if(vs.size() % 2 != 0){
                printf("%.1f\n",double(vs[vs.size()/2]));
                sum += double(vs[vs.size()/2]);
            }else{
                printf("%.1f\n",double(vs[vs.size()/2] + vs[(vs.size()/2)-1])/2);
                sum += double(vs[vs.size()/2] + vs[(vs.size()/2)-1])/2;
            }
        }
        vs.clear();
    }
    printf("%.1f",sum);
    return 0;
}

