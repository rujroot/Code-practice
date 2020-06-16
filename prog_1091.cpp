/*  1091 : treemic
    ST : 16.43
    Read : 16.43 - 16.45 = 2 Min
    ED : 17.15
    Total : 32 min
    O(N)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int N,x,y,mem[300001],Max;
vector<int> v[300001];
int dp(int i){
    if(mem[i] != 0)
        return mem[i];
    for(auto u : v[i]){
        mem[i] = max(mem[i],1 + dp(u));
    }
    return mem[i];
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N-1;++i){
        scanf("%d %d",&x,&y);
        v[min(x,y)].push_back(max(x,y));
    }
    for(int i=1;i<N;++i){
        dp(i);
        Max = max(Max,mem[i]);
    }
    printf("%d",Max+1);
    return 0;
}

