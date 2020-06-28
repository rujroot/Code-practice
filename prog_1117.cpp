/*  1117 : mission
    ST : 11.01 26/6/63
    Rest : 0.10 - 14.03 27/6/63
    Rest : 20.02 - 20.35 27/6/63
    Rest : 0.30 - 8.02 28/6/63
    ED : 12.01 28/6/63
    O(n log n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
long long int N,x,y,mem[100010][5];
vector<pair<long long int,long long int>> v;
bool CustomSort(const pair<long long int,long long int> &a,const pair<long long int,long long int> &b){
    return (-(a.first*2) + a.second > -(b.first*2) + b.second);
}
int main()
{
    scanf("%lld",&N);
    for(long long int i=0;i<N;++i){
        scanf("%lld %lld",&x,&y);
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),CustomSort);
    for(long long int i = N-1 ;i >= 0; --i){
        if(-(v[i].first*2) + v[i].second + mem[i+1][0] >= mem[i+1][0] - (2*mem[i+1][1] + 1)){
            mem[i][0] = -(v[i].first*2) + v[i].second + mem[i+1][0];
            mem[i][1] = mem[i+1][1];
        }else{
            mem[i][0] = mem[i+1][0] - (2*mem[i+1][1] + 1);
            mem[i][1] = mem[i+1][1]+1;
        }
    }
   // printf("%lld",mem[0][0]);
    for(int i=0;i<N;++i){
        printf("%lld %lld\n",v[i].first,v[i].second);
    }
    return 0;
}

