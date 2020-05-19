/*  1057 : Include
    ST : 19.27 19/5/63 ED : 0.05 20/5/63
    O(n^3)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int N,k,x;
vector<int> v[1010];
bool Rp,Table[1010],visited[1010];
int ch(int po){
    if(visited[po] or Table[po]){
        Rp = true;
        return 0;
    }
    visited[po] = true;
    Table[po] = true;
    if(v[po].size() == 0){
        return 0;
    }
    for(int i=0;i<v[po].size();++i){
        ch(v[po][i]-1);
    }
    return 0;
}
int main()
{

    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&k);
        for(int j=0;j<k;++j){
            scanf("%d",&x);
            v[i].push_back(x);
        }
    }
    for(int i=0;i<N;++i){
        if(v[i].size() == 0){
            printf("NO\n");
            continue;
        }
        for(int j=0;j<N;++j){
           Table[j] = false;
           visited[j] = false;
        }
        Rp = false;
        for(int j=0;j<v[i].size();++j){
           ch(v[i][j]-1);
        }
        if(Rp){
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}

