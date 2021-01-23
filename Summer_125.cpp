#include<bits/stdc++.h>
using namespace std;

map<int, long long> m, sum;
vector<int> po;

int main(){
    int M, Q;
    scanf("%d %d", &M ,&Q);

    for(int i = 1; i <= M; ++i){
        int l, r, x; scanf("%d %d %d", &l, &r, &x);
        m[l] += x;
        m[r + 1] -= x;
    }

    long long tamp = 0;
    for(auto y : m){
        m[y.first] = y.second + tamp;
        tamp = m[y.first];
    }

    tamp = 0;
    long long num = 0, total = 0;
    for(auto y : m){
        sum[y.first] += (y.first - num - 1) * m[num] + tamp + m[y.first];
        po.push_back(y.first);
        num = y.first;
        tamp = sum[y.first];
    }

    vector<int>::iterator po1, po2;
    for(int i = 1; i <= Q; ++i){
        int l, r; scanf("%d %d", &l, &r);
        l--;
        po1 = lower_bound(po.begin(), po.end(), l);
        po2 = lower_bound(po.begin(), po.end(), r);
        long long sum1 = sum[po[po1 - po.begin()]], sum2 = sum[po[po2- po.begin()]];
        if(po[po1 - po.begin()] != l){
            sum1 = sum[po[po1 - po.begin() - 1]];
            sum1 += (l - po[po1 - po.begin() - 1]) * m[po[po1 - po.begin() - 1]];
        }
            
        if(po[po2 - po.begin()] != r){
            sum2 = sum[po[po2- po.begin() - 1]];
            sum2 += (r - po[po2 - po.begin() - 1]) * m[po[po2 - po.begin() - 1]];
        }
            
        printf("%lld\n", sum2 - sum1);

    }

}
