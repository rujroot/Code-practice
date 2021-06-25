#include<bits/stdc++.h>
using namespace std;

int N, K, T;
vector<int> g[100010];
bool visited[100010];

void Do(int u){
    //printf("%d", u);
    if(visited[u]) return;
    visited[u] = true;
    //printf("%d ", u);
    for(int x : g[u]){
         Do(x);
    }
    T--;
   //printf("in");

}

int main(){
    scanf("%d %d %d", &N, &K, &T);
    for(int i = 1; i <= N; ++i){
        int L, P; scanf("%d %d", &L, &P);
        for(int j = 0; j < P; ++j){
            int q; scanf("%d", &q);
            g[L].push_back(q);
        }
    }

    for(int i = 1; i <= K; ++i){
        for(int x : g[i]){
            printf("%d %d)", x, i);
            Do(x);

            if(T <= 0){
                printf("%d", i);
                return 0;
            }
        }
    }
}
