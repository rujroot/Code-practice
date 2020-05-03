/*  1036 : equipped
    ST : 12.09 29/4/63 ED : 22.11 2/5/63
    o(n^2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int n,k,x,dp[10010][300],All;
vector<int> price,work(10010,0);
int solve(int i,int ch){
    if(ch == All){
        return 0;
    }
    if(i < 0){
        return 2e9;
    }
    if(dp[i][ch] != 0)
        return dp[i][ch];
    return dp[i][ch] = min(price[i] + solve(i-1,ch|work[i]),solve(i-1,ch));
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        price.push_back(x);
        for(int j=0;j<k;++j){
            scanf("%d",&x);
            work[i] += x * (1<<j);
        }
        All = All|work[i];
    }
    printf("%d",solve(n-1,0));
    return 0;
}

