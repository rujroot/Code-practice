/*  1074 : Mravojed
    ST 18.54 26/5/63 ED : 21.55 27/5/63
    O(n^5)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
char Table[110][110];
bool visited[110][110];
int R,C,x;
vector<pair<pair<int,int>,int>> v;
bool can(int r,int c,int n){
    bool never = false;
    for(int i=r;i<r+n;++i){
        for(int j=c;j<c+n;++j){
            if(Table[i][j] == '.'){
                return false;
            }
            if(!visited[i][j])
                never = true;
        }
    }
    if(!never)
        return false;
    for(int i=r;i<r+n;++i){
        for(int j=c;j<c+n;++j){
           visited[i][j] = true;
        }
    }
    return true;
}
int main()
{
    scanf("%d %d ",&R,&C);
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            scanf("%c",&Table[i][j]);
            if(Table[i][j] == 'x')
                x++;
        }
        getchar();
    }
    for(int k=min(R,C);k>=1;--k){
        for(int i=0;i<=R-k;++i){
            for(int j=0;j<=C-k;++j){
                if(can(i,j,k)){
                    v.push_back({{i,j},k});
                }
            }
        }
    }
   if(v.size() == 1){
        printf("%d %d %d\n%d %d %d",v[0].first.first+1,v[0].first.second+1,v[0].second,v[0].first.first+1,v[0].first.second+1,v[0].second);
    }else if(v.size() != 2){
        for(int i=1;i<v.size();++i){
             printf("%d %d %d\n%d %d %d",v[0].first.first+1,v[0].first.second+1,v[0].second,v[v.size()-1].first.first+1,v[v.size()-1].first.second+1,v[v.size()-1].second);
                return 0;
        }
    }else{
        for(int i=0;i<v.size();++i){
            printf("%d %d %d\n",v[i].first.first+1,v[i].first.second+1,v[i].second);
        }
    }

    return 0;
}

