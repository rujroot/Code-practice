/*  1105 : Cars
    ST : 22.30 22/6/63
    Read : 22.30 - 22.35 : 5 Min
    ED : 22.51 22/6/63
    O(n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int n,x,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        v.push_back(x);
    }
    nth_element(v.begin(),v.begin()+k-1,v.end(),greater<int>());
    printf("%d",v[k-1]);
    return 0;
}

