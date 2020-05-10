/*  1052 : Domino
    ST : 17.40 8/5/2563 ED : 22.49 8/5/2563
    o(n^2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<long long int,long long int>> v;
    pair<pair<int,char>,int> ans = {{2e9,'L'},0};
    int N;
    long long int XI,HI;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%lld %lld",&XI,&HI);
        v.push_back({XI,HI});
    }
    for(int i=v.size()-1;i >= 0;--i){
        int curr = v[i].first - v[i].second,po = i-1,con = 1;
        while(po >= 0 and curr < v[po].first){
            if(curr >= v[po].first - v[po].second){
                curr = v[po].first - v[po].second;
            }
            po--;
            con++;
        }
        if(ans.second <= con){
            ans.first.first = i;
            ans.second = con;
        }
    }
    for(int i=0;i<v.size();++i){
        int curr = v[i].first + v[i].second,po = i+1,con = 1;
        while(po < v.size() and curr > v[po].first){
            if(curr <= v[po].first + v[po].second){
                curr = v[po].first + v[po].second;
            }
            po++;
            con++;
        }
        if(ans.second < con){
            ans.first.first = i;
            ans.second = con;
            ans.first.second = 'R';
        }
        else if(ans.first.first > i and con == ans.second){
            ans.first.first = i;
            ans.second = con;
            ans.first.second = 'R';
        }
    }
    printf("%d %c",ans.first.first+1,ans.first.second);
    return 0;
}

