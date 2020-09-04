#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    vector<pair<long long, long long>> v;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i){
        long long a, b; scanf("%lld %lld" ,&a ,&b);
        v.push_back({a, b});
    }
    for (int i = 0 ;i < M; ++i){
        long long f; scanf("%lld", &f);
        for(int j = 0;j < N; ++j){
            if(v[j].first <= f){
                swap(v[j].first, v[j].second);
            }
        }
    }
    for(int i = 0; i < N; ++i){
        printf("%d\n", v[i].first);
    }
    return 0;
}
