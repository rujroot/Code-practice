/*  1042 : Mafia
    ST : 16.00 30/4/2563 ED : 16.35 30/4/2563
    O(n^2);
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int R,C,n,x,y,z,ans = -1,po,ch;
    vector<pair<pair<int,int>,int>> v;
    scanf("%d %d %d",&R,&C,&n);
    for(int i=0;i<n;++i){
        scanf("%d %d %d",&x,&y,&z);
        v.push_back({{x,y},z});
    }
    for(int i=0;i<=R;++i){
        ch = 0;
        for(int j=0;j<n;++j){
            po = v[j].first.second;
            if(po - v[j].second <= i and po + v[j].second >= i)
                ch++;
        }
        ans = max(ans,ch);
    }
    for(int i=0;i<=C;++i){
        ch =0;
        for(int j=0;j<n;++j){
            po = v[j].first.first;
            if(po - v[j].second <= i and po + v[j].second >= i)
                ch++;
        }
        ans = max(ans,ch);
    }
    printf("%d",ans);
    return 0;
}

