/*  1088 : iguana
    ST : 0.39 14/6/63 ED 23.53 14/6/63
    O(M)
    rujroot
*/
#include <bits/stdc++.h>
using namespace std;
long long int x,y,N,M,ans,diff;
map<long long int,long long int> a;
vector<pair<long long int,long long int>> v;
char c;
int main()
{
    scanf("%lld %lld",&N,&M);
    for(int i=0;i<M;++i){
        scanf("%lld %lld",&x,&y);
        a[x]++;
        a[y+1]--;
    }
    v.push_back({0,0});
    for(u : a){
        v.push_back({u.second,u.first});
    }
    scanf(" %c",&c);
    for(int i=1;i<v.size();++i){
        v[i].first += v[i-1].first;
    }

    for(int i=0;i<v.size();++i){
        if( (i == 0 and v[i+1].second == 1) or (i == v.size()-1 and v[v.size()-1].second == N+1)){
            continue;
        }
        diff = v[i+1].second - v[i].second;
        if(i == 0){
            diff = v[i+1].second-1;
        }
        if(i == v.size()-1){
            diff = N-v[v.size()-1].second+1;
        }
        if(c == 'R'){
          if(v[i].first%3 == 1) ans += 2*diff;
          if(v[i].first%3 == 2) ans += 1*diff;
        }else if(c == 'G'){
          if(v[i].first%3 == 0) ans += 1*diff;
          if(v[i].first%3 == 2) ans += 2*diff;
        }else{
          if(v[i].first%3 == 0) ans += 2*diff;
          if(v[i].first%3 == 1) ans += 1*diff;
        }
    }
    printf("%lld",ans);
    return 0;
}

