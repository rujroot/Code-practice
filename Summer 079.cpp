#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K, Po = 1;
    vector<int> v;
    scanf("%d %d", &N, &K);
    v.push_back(0);
    for(int i = 1; i <= N; ++i){
        v.push_back(i);
    }
    for(int i = 0; i < N; ++i){
        int S = v.size() - 1;
        Po = (Po + K - 1) % (S);
        if(Po == 0)
            Po = S;
        printf("%d\n", v[Po]);
        v.erase(v.begin() + Po);
    }
    return 0;
}
