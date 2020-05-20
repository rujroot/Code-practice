/*  1065 : frame
    ST : 18.21 20/5/63 ED : 22.10 20/5/63
    o(n^2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,M,x1,y1,x2,y2;
    scanf("%d %d",&N,&M);
    vector<pair<pair<int,int>,pair<int,int>>> v;
    for(int i=0;i<N;++i){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        v.push_back({{x1,y1},{x2,y2}});
    }
    for(int i=0;i<M;++i){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int sum = 0;
        for(int j=0;j<v.size();++j){
            if((max(x1,v[j].first.first) < min(x2,v[j].second.first)) and (max(y2,v[j].second.second) < min(y1,v[j].first.second))){
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

