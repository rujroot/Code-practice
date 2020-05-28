/*  1075 : worm
    ST : 22.16 28/5/63 ED : 22.54 28/5/63
    O(n log n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int N,x,y,sum = 0,power;
    double avg = 0;
    pair<long long int,long long int> Ans;
    vector<pair<long long int,long long int>> v;
    scanf("%lld",&N);
    for(int i=0;i<N;++i){
        scanf("%lld %lld",&x,&y);
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    v.push_back({0,0});
    for(int i=0;i<v.size()-1;++i){
        sum += v[i].second;
        power = v[i].first;
        if(v[i].first != v[i+1].first and double(sum)/double(power) > avg){
            avg = double(sum)/double(power);
            Ans = {sum,power};
        }
    }
    printf("%lld %lld",Ans.first,Ans.second);
    return 0;
}

