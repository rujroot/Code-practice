#include <bits/stdc++.h>
using namespace std;
map <long long int, long long int> m[5];
map <pair<long long int , long long int>, long long int> inter;
int main()
{
    long long int n, x, y;
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i){
        scanf("%lld %lld", &x, &y);
        m[0][x]++;
        m[1][y]++;
        inter[{x, y}]++;
    }
    long long int Ans = 0;
    for (auto v : m[0]){
        Ans += (v.second) * (v.second - 1) / 2;
    }
    for (auto v : m[1]){
        Ans += (v.second) * (v.second - 1) / 2;
    }
    for (auto v : inter){
        Ans -= (v.second) * (v.second - 1) / 2;
    }
    printf("%lld", Ans);
    return 0;
}
