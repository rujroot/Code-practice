/*  1073 : mravi
    ST : 18.12 25/5/63 ED : 14.56 25/5/63
    O(n log n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int L,T,N,curr,k,x,walk;
    char y,path;
    vector<pair<int,char>> v;
    vector<int> Ans;
    bool po;
    scanf("%d %d %d",&L,&T,&N);
    for(int i=0;i<N;++i){
        scanf("%d",&x);
        scanf(" %c",&y);
        v.push_back({x,y});
    }
    for(int i=0;i<N;++i){
        curr = v[i].first;
        path = v[i].second;
        walk = T%(2*L);
        if(path == 'L'){
            curr -= walk;
            if(-(curr) > L){
                Ans.push_back(L - (-curr - L));
            }
            else if(curr < 0){
                Ans.push_back(-(curr));
            }else{
                Ans.push_back(curr);
            }

        }else{
            curr += walk;
            if(curr - L > L){
                Ans.push_back((curr - L) % L);
            }
            else if(curr > L){
                Ans.push_back(L - (curr - L));
            }else{
                Ans.push_back(curr);
            }
        }
    }
    sort(Ans.begin(),Ans.end());
        for(int i=0;i<Ans.size();++i){
            printf("%d ",Ans[i]);
        }
    return 0;
}

