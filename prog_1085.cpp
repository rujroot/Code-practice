/*  1085 : explore
    ST : 14.00 12/6/63 ED : 14.40 12/6/63
    O(m+k);
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int x,y,n,m,k,mem[500010];
bool block[500010];
vector<int> warp[500010];
int dp(int i){
    if(i >= n)
        return i;
    if(mem[i] != 0)
        return mem[i];
    if(block[i+1]){
        mem[i] = max(mem[i] , i);
    }else{
        mem[i] = max(mem[i] , dp(i+1));
    }
    for(auto u : warp[i])
        mem[i] = max(mem[i] , dp(u));
    return mem[i];
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;++i){
        scanf("%d %d",&x,&y);
        warp[x].push_back(y);
    }
    for(int i=0;i<k;++i){
        scanf("%d",&x);
        block[x+1] = true;
    }
    int Max = dp(1);
    if(Max == n){
        printf("1");
        return 0;
    }
    printf("0 %d",mem[1]);
    return 0;
}

