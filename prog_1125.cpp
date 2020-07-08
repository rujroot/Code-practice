/*  1125 : distance
    ST : 16.42 8/7/2563
    Read : 16.42 - 16.47 : 5 Min
    ED : 22.49 8/7/63
    O(n log n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
long long int N,n1,n2,sumx,sumy,p;
vector<long long int> X,Y;
int main()
{
    scanf("%lld",&N);
    for(int i=0;i<N;++i){
        scanf("%lld %lld",&n1,&n2);
        X.push_back(n1);
        Y.push_back(n2);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    p = 0;
    for(int i=0;i<N;++i){
        sumx += (X[i] * i - p);
        p += X[i];
    }
    p = 0;
    for(int i=0;i<N;++i){
        sumy += (Y[i] * i - p);
        p += Y[i];
    }
    printf("%lld",sumx+sumy);
    return 0;
}

