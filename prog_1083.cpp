/*  1083 : stock
    ST : 19.42 9/6/63 ED : 14/6/63
    O(n+q);
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int x,y,n,q,mem[1000010];
vector<int> v;
int main()
{
    v.push_back(0);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        v.push_back(x);
    }
    mem[n] = 0;
    for(int i=n;i>=1;--i){
        mem[i] = max(mem[i],max(mem[i+1],-v[i] + v[i+1] + mem[i+1]));
    }
    scanf("%d",&q);
    for(int i=0;i<q;++i){
        scanf("%d %d",&x,&y);
        printf("%d\n",mem[x]-mem[y]);
    }
    return 0;
}

