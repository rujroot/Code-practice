/*  1081 : blowblock
    ST : 13.39 7/6/63 ED : 15.53 7/6/63
    O(n log n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int N,x;
long long int sum;
vector<int> OO,OE,EO,EE;
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            scanf("%d",&x);
            if(i%2 == 0 and j%2 == 0)
                EE.push_back(x);
            else if(i%2 == 0 and j%2 != 0)
                EO.push_back(x);
            else if(i%2 != 0 and j%2 == 0)
                OE.push_back(x);
            else
                OO.push_back(x);
        }
    }
    sort(EE.begin(),EE.end());
    sort(EO.begin(),EO.end());
    sort(OE.begin(),OE.end());
    sort(OO.begin(),OO.end());
    while(!EE.empty()){
        sum += (EE.back() * EO.back() * OE.back() * OO.back());
        EE.pop_back();
        EO.pop_back();
        OE.pop_back();
        OO.pop_back();
    }
    printf("%lld",sum);
    return 0;
}

