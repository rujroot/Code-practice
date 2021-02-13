//ST : 22.25 13/2/2564

#include<bits/stdc++.h>
using namespace std;

bool Visited[2010];
int Group = 1, Color[2010];
vector<int> v[2010];

int main(){
    int N, M, T;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int x, y; scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d", &T);

    int po;
    queue<int> q;
    while(true){
        //printf("Yes");
        if(q.empty()){
            bool end = true;
            for(int i = 1; i <= N; ++i){
                if(!Visited[i]){
                    q.push(i);
                    end = false;
                    Group = (Group * 2) % 1000000007;
                    break;
                }
            }

            if(end) break;

        }

        Visited[q.front()] = true;
        Color[q.front()] = 1;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            for(auto u : v[f]){
                if(Color[u] == 0){
                    Visited[u] = true;
                    Color[u] = -Color[f];
                    q.push(u);
                }
                else if(Color[u] == Color[f]){
                    if(T == 1 or T == 2)
                        printf("No");
                    else
                        printf("0");
                    return 0;
                }
            }
        }

    }

    if(T == 1) printf("Yes");
    else if(T == 2){
        printf("Yes\n");
        for(int i = 1; i <= N; ++i){
            if(Color[i] == 1)
                printf("%d ", i);
        }printf("\n");
        for(int i = 1; i <= N; ++i){
            if(Color[i] == -1)
                printf("%d ", i);
        }
    }
    else printf("%d", Group);
}