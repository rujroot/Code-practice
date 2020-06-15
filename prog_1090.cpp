/*  1090 : cocktail

    ST : 10.10 15/6/63
    Read : 10.10 - 10.15 : 5 Min
    Rest : 11.14 - 12.38  (Lunch) : 1 H 24 M
    Rest : 13.00 - 15.55  (Study) : 2 H 55 M
    ED : 16.20 15/6/63
    Total : 370 M - 259 M = 111 M

    O(n^2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
map<int,int> m;
int N,A,x;
long long int ans;
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&x);
        m[x]++;
    }
    scanf("%d",&A);
    for(auto u : m){
        if(A-u.first == u.first and m[u.first] != 1){
            for(int i=1;i<m[u.first];++i){
                ans += (long long int)i;
            }
        }
        else
            ans += (long long int)m[A-u.first]*(long long int)m[u.first];
        m[u.first] = 0;
        m[A-u.first] = 0;
    }
    printf("%lld",ans);
    return 0;
}

