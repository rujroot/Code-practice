#include<bits/stdc++.h>
using namespace std;

int n, k;
pair<int, int> p[11];

long long Solve(int w, int i){
    if(i > n)
        return 0;
    if(w >= p[i].first)
        return max( Solve(w - p[i].first, i + 1) + p[i].second, Solve(w , i + 1));
    else
        return Solve(w, i + 1);
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d %d", &p[i].first , &p[i].second);
    }

    printf("%lld",Solve(k,1));
}
