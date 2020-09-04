
#include <bits/stdc++.h>

using namespace std;

int main()
{
    printf("%02d",101);
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++i){
        int x; scanf("%d", &x);
        v.push_back({x, i + 1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i){
        if(n < 10){
             printf("%d_problem%d\n", i + 1, v[i].second);
        }else{
            printf("%02d_problem%d\n", i + 1, v[i].second);
        }
    }
    return 0;
}
