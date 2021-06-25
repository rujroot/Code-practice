#include<bits/stdc++.h>
#define N 110
using namespace std;
typedef tuple<int, int, int> tiii;

char w[N][N];
bool visited[N][N];
pair<int, int> p[N][N];

int main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf(" %c", &w[i][j]);
        }
    }
    queue<tiii> q;
    q.emplace(1, 1, 1);
    while(!q.empty()){
        int i = get<0>(q.front()), j = get<1>(q.front()), cnt = get<2>(q.front());
        q.pop();
        if(i > n or j > m or i <= 0 or j <= 0) continue;
        if(visited[i][j]){
            printf("%d\n%d %d", cnt, i, j);
            return 0;
        }
        visited[i][j] = true;
        char c = w[i][j];
        int pi = p[i][j].first, pj = p[i][j].second;
        if( !(pi == i and pj == j + 1) and (c == 'R' or c == 'B')){
            q.emplace(i , j + 1, cnt + 1);
            p[i][j + 1] = {i, j};
        }if( !(pi == i + 1 and pj == j) and (c == 'D' or c == 'B')){
            q.emplace(i + 1, j, cnt + 1);
            p[i + 1][j] = {i, j};
        }if( !(pi == i and pj == j - 1) and (w[i][j - 1] == 'R' or w[i][j - 1] == 'B')){
            q.emplace(i , j - 1, cnt + 1);
            p[i][j - 1] = {i, j};
        }if( !(pi == i - 1 and pj == j) and (w[i - 1][j] == 'D' or w[i - 1][j] == 'B')){
            q.emplace(i - 1, j, cnt + 1);
            p[i - 1][j] = {i, j};
        }
    }
}
