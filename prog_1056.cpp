/*  1056 : Hands
    ST : 17.43 11/5/63 ED : 18.23 11/5/63
    O(n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,K,x;
    vector<int> v;
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;++i){
        scanf("%d",&x);
        v.push_back(x);
    }
    int Ans = 0,Max = -2e9,r = 1;
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;--i){
        if(r % K == 0 or i == 0){
            Ans += Max;
            Max = -2e9;
            r = 1;
        }else{
            Max = max(Max,v[i]);
            r++;
        }
    }
    printf("%d",Ans);
    return 0;
}

