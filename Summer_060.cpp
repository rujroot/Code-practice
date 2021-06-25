#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int x; scanf("%d", &x);
        v.emplace_back(x, i);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i){
        printf("%d\n", v[i].second);
    }
}
