#include <bits/stdc++.h>
using namespace std;
int main()
{
   int y,bw=1,bs=0,bwpost,ed=0;
   vector<int> Ans;
   pair<int,int> C[30];
   while(true){
    scanf("%d",&y);
    if(y != -1){
        Ans.push_back(y);
        if(y > ed){
            ed = y;
        }
    }else{
        break;
    }
   }
   for(int i=1;i<=ed;++i){
    bwpost = bw;
    bw += bs+1;
    bs += bwpost - bs;
    C[i] = {bw,bw+bs+1};
   }
   for(int i=0;i<Ans.size();++i){
    printf("%d %d\n",C[Ans[i]].first,C[Ans[i]].second);
   }
    return 0;
}
