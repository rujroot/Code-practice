/*
    ST : 18.43 6/5/63
*/
#include <bits/stdc++.h>
using namespace std;
int N,M,Ai,Li,Si,Position[101001];
vector<pair<int,int>> v[100100];
bool CustomSort(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first > b.first)
        return true;
    return (a.second < b.second and a.first == b.first);
}
int main()
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;++i){
        scanf("%d %d %d",&Ai,&Li,&Si);
        v[Position[Li]].push_back({Si,Ai});
        Position[Li]++;
    }
    for(int i=0;i<100100;++i){
        if(v[i].empty())
            return 0;
        sort(v[i].begin(),v[i].end(),CustomSort);
        printf("%d\n",v[i].front().second);
    }
    return 0;
}

