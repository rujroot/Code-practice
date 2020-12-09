#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<long long> v;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        long long x; scanf("%lld", &x);
        v.push_back(x);
    }
    
    long long  Max = v[0] , ans = v[0];
    for(int i = 1; i < n; ++i){
        Max = max(v[i] , Max + v[i]);
        ans = max(ans , Max);
    }
    printf("%lld", ans);
}