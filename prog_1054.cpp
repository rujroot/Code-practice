/*  1054 : Tile
    ST : 13.00 9/5/2563 ED : 14.45 9/5/2563
    O(n^2) T : 0.176
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
bool customsort(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b){
        if (a.first.second > b.first.second)
            return true;
        return (a.first.second == b.first.second and a.first.first < b.first.first);
}
int main()
{
    vector<pair<pair<int,int>,int>> v;
    long long int ans=0;
    int n,x,y,z,po,Xi,Xj,Yi,Yj,Ri,Rj,Poxij,Poyij,Porij;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d %d",&x,&y,&z);
        v.push_back({{x,y},z});
    }
    sort(v.begin(),v.end(),customsort);
    for(int i=0;i<v.size()-1;++i){
         po = i+1;
         Xi = v[i].first.first,Yi=v[i].first.second,Ri=v[i].second,Xj=v[po].first.first,Yj=v[po].first.second,Rj=v[po].second;
        while(po < v.size() and !(Xj-10 > Xi+Ri and Yj+10 < Yi-Ri)){
             Poxij=(Xi-Xj)*(Xi-Xj),Poyij=(Yi-Yj)*(Yi-Yj),Porij=(Ri+Rj)*(Ri+Rj);
             if(Poxij + Poyij < Porij){
                ans++;
             }
             po++;
             Xj=v[po].first.first,Yj=v[po].first.second,Rj=v[po].second;
        }
    }
   printf("%lld",ans);
    return 0;
}

