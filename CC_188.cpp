#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> m;
vector<int>::iterator it;

int main(){
    int N, Q; scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; ++i){
        int x; scanf("%d", &x);
        m[x].push_back(i);
    }
    for(int i = 0; i < Q; ++i){
        int L, R, C; scanf("%d %d %d", &L, &R, &C);
        if(m[C].empty()){
            printf("0\n");
            continue;
        }
        it = lower_bound(m[C].begin(), m[C].end(), L);
        int poL = it - m[C].begin();
        it = upper_bound(m[C].begin(), m[C].end(), R);
        int poR = it - m[C].begin();
        printf("%d\n", poR - poL);
    }
}
