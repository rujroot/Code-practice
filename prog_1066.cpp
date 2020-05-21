/*  1066 : atom
    ST : 10.12 21/5/63 ED : 13.25 21/5/63
    (n^2 log n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
bool CS(const pair<int,int> &a , const pair<int,int> &b){
    if(a.first < b.first)
        return true;
    if(a.first <= b.first and a.second > b.second)
        return true;
    return false;
}
int main()
{
    int N,sum=0,x,p1,p2;
    vector<int> v;
    vector<pair<int,int>> po;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&x);
        v.push_back(x);
    }
    while(v.size() != 0 and v.size() != 1){
        for(int i=0;i<v.size()-1;++i){
            p1=v[i] , p2=v[i+1];
            po.push_back({max(p1,p2) - min(p1,p2),i});
        }
        sort(po.begin(),po.end(),CS);
        sum += po.back().first;
        v.erase(v.begin()+po.back().second);
        v.erase(v.begin()+po.back().second);
        po.clear();
    }
    printf("%d",sum);
    return 0;
}

