#include<bits/stdc++.h>
#define N 40010
using namespace std;
typedef tuple<int, int, int> tiii;;

vector<int> L[N], R[N], U[N], D[N];
bool visited[N];
int Ans[210][210];

/*int Find(int u){
    if(!U[u].empty()) return Find(U[u][0]);
    else if(!L[u].empty()) return Find(L[u][0]);
    return u;
}*/

int main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0; i < (n * m) - 1; ++i){
        int a, b; char c;
        scanf("%d", &a);
        scanf(" %c", &c);
        scanf("%d", &b);
        if(c == 'U'){
            D[a].push_back(b);
            U[b].push_back(a);
        }else{
            R[a].push_back(b);
            L[b].push_back(a);
        }
    }

    //int s = Find(0);
    queue<tiii> q;
    vector<tiii> vAns;
    int mini = 0, minj = 0;
    q.emplace(0, 0, 0);
    while(!q.empty()){
        int u = get<2>(q.front()), i = get<0>(q.front()), j = get<1>(q.front());
        q.pop();

        //if(i < 0 or j < 0 or i >= n or j >= m) continue;
        if(visited[u]) continue;
        visited[u] = true;
        vAns.emplace_back(i, j, u);
       // printf("%d %d %d\n", i, j, u);
        if(i <= mini and j <= minj){
            mini = i;
            minj = j;
        }

        if(!L[u].empty())
            q.emplace(i, j - 1, L[u][0]);
        if(!R[u].empty())
            q.emplace(i, j + 1, R[u][0]);
        if(!U[u].empty())
            q.emplace(i - 1, j, U[u][0]);
        if(!D[u].empty())
            q.emplace(i + 1, j, D[u][0]);

    }

   // printf("%d %d\n",mini,minj);
    for(tiii x : vAns){

        int u = get<2>(x), i = get<0>(x), j = get<1>(x);
        Ans[abs(i - mini)][abs(j - minj)] = u;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            printf("%d ", Ans[i][j]);
        }printf("\n");
    }

}
