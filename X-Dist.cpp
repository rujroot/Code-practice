#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v[100010];
bool visited[100010];

int main(){
    int N, M, X;
    
    scanf("%d %d %d", &N, &M, &X);
    for(int i = 1; i <= M; ++i){
        int x, y, z; scanf("%d %d %d", &x, &y, &z);
        v[x].push_back({y, z});
        v[y].push_back({x, z}); 
    }

    long Size_X = 1, Size_X1 = 1;

    
    for(int i = 1; i <= N; ++i){
        long long Size = 1;
        queue<int> q;
        if(visited[i])
            continue;
        q.push(i);
        while (!q.empty())
        {
            int F = q.front();
            visited[F] = true;
            q.pop();
            for(auto u: v[F]){
                if(visited[u.first] or u.second > X)
                    continue;
                visited[u.first] = true;
                q.push(u.first);
                Size++;
            }
        }
        Size_X += Size * (Size - 1) / 2;  
    }

    for(int i = 1; i <= 100010; ++i){
        visited[i] = false;
    }

    for(int i = 1; i <= N; ++i){
        long long Size = 1;
        queue<int> q;
        if(visited[i])
            continue;
        q.push(i);
        while (!q.empty())
        {
            int F = q.front();
            visited[F] = true;
            q.pop();
            for(auto u: v[F]){
                if(visited[u.first] or u.second > X - 1)
                    continue;
                visited[u.first] = true;
                q.push(u.first);
                Size++;
            }
        }
        Size_X1 += Size * (Size - 1) / 2;  
    }
    printf("%lld", Size_X - Size_X1);
}