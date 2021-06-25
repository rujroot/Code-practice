#include<bits/stdc++.h>
using namespace std;

int main(){
    int Q; scanf("%d", &Q);
    for(int q = 1; q <= Q; ++q){
        set<long long> s;
        long long N, K; scanf("%lld %lld", &N, &K);
        s.insert(N);
        map<long long, long long> m;
        m[N] = 1;
        long long P = 0;
        for(long long i = 1; i <= K; ++i){
            long long S = *(prev(s.end()));
            long long D1 = (S - 1) / 2;
            long long D2 = (S) / 2;
            P += m[S];
            if(P >= K){
                printf("Case #%d: %lld %lld\n", q, max(D1, D2), min(D1, D2));
                break;
            }else{
                s.erase(S);
                s.insert(D1); s.insert(D2);
                m[D1]+=m[S];
                m[D2]+=m[S];
                m[S]=0;
            }
        }
    }
}
