#include <bits/stdc++.h>

using namespace std;

int n, k, Mem[10010];
vector<int> v;
bool visited[10010];

int main()
{

    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; ++i){
        int num; scanf("%d", &num);
        v.push_back(num);
    }
    for(int i = 0; i <= n; ++i){
        Mem[i] = 2e9;
    }
    Mem[0] = 0;
    for(int money = 1; money <= n; ++money){
        for(int i = 0; i < k; ++i){
            if(v[i] <= money){
                 Mem[money] = min(Mem[money - v[i]] + 1, Mem[money]);
            }

        }
    }
    printf("%d",Mem[n]);
    return 0;
}
