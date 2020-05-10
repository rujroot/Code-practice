/*  1049 : Runner
    ST : 18.43 6/5/63 ED : 12.21 7/5/63
    O(n log n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int N,M,Ai,Li,Si,Position[10010];
vector<pair<int,pair<int,int>>> v[100100];
bool CustomSort(const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b){
    if(a.second.first > b.second.first)
        return true;
    return (a.first < b.first and a.second.first >= b.second.first);
}
int main()
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;++i){
        scanf("%d %d %d",&Ai,&Li,&Si);
        v[Position[Li]].push_back({Li,{Si,Ai}});
        Position[Li]++;
    }
    for(int i=0;i<100100;++i){
        if(v[i].empty())
            return 0;
        sort(v[i].begin(),v[i].end(),CustomSort);
        printf("%d\n",v[i].front().second.second);
    }
    return 0;
}

