#include<bits/stdc++.h>
using namespace std;



int main(){
    int T; scanf("%d", &T);
    for(int Q = 1; Q <= T ; ++Q){
        int M, N, D, Ans = 2e9;
        scanf("%d %d %d", &M, &N, &D);

        map<pair<int, int>, bool> visited;
        map<pair<int, int>, int> dist;
        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[{0 , 0}] = 0;

        while(!q.empty()){
            int F = q.front().first, S = q.front().second;
            q.pop();
            if(F == D or S == D){
                Ans = dist[{F , S}];
                break;
            }

            if(visited[{F, S}])
                continue;
            visited[{F, S}] = true;

            if(!visited[{M, S}]){
                dist[{M, S}] = dist[{F, S}] + 1;
                q.push({M, S});
            }

            if(!visited[{F, N}]){
                dist[{F, N}] = dist[{F, S}] + 1;
                q.push({F, N});
            }

            if(!visited[{0, S}]){
                dist[{0, S}] = dist[{F, S}] + 1;
                q.push({0, S});
            }

            if(!visited[{F, 0}]){
                dist[{F, 0}] = dist[{F, S}] + 1;
                q.push({F, 0});
            }

            int SpaceF = M - F;
            if(!visited[{F + min(SpaceF, S) , S - min(SpaceF , S)}]){
                dist[{F + min(SpaceF, S) , S - min(SpaceF , S)}] = dist[{F, S}] + 1;
                q.push({F + min(SpaceF, S) , S - min(SpaceF , S)});
            }

            int SpaceS = N - S;
            if(!visited[{F - min(SpaceS, F), S + min(SpaceS, F)}]){
                dist[{F - min(SpaceS, F), S + min(SpaceS, F)}] = dist[{F, S}] + 1;
                q.push({F - min(SpaceS, F), S + min(SpaceS, F)});
            }
        }
        if(Ans == 2000000000)
            printf("-1\n");
        else
            printf("%d\n", Ans);
    }
}
