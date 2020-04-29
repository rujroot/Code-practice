/*  1037 : Slikar
    ST : 17.39 ED : 21.00
    O(n^3)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
bool visited[60][60];
int main()
{
    queue<pair<int,int>> qS,qW,cpy;
    string x;
    int R,C,walk=0;
    vector<char> Table[60];
    vector<pair<int,int>> adj[60][60];
    scanf("%d %d ",&R,&C);
    for(int i=0;i<R;++i){
        cin >> x;
        for(int j=0;j<C;++j){
            Table[i].push_back(x[j]);
            if(x[j] == 'S'){
                qS.push({i,j});
            }
            if(x[j] == '*'){
                qW.push({i,j});
            }
            if(i+1 < R){
                adj[i][j].push_back({i+1,j});
            }
            if(i-1 >= 0){
                adj[i][j].push_back({i-1,j});
            }
            if(j+1 < C){
                adj[i][j].push_back({i,j+1});
            }
            if(j-1 >= 0){
                adj[i][j].push_back({i,j-1});
            }
        }
        getchar();
    }
    while(true){
        while(!qW.empty()){
            pair<int,int> u = qW.front();
            qW.pop();
            for(auto v:adj[u.first][u.second]){
                int i = v.first,j = v.second;
                if(Table[i][j] == '.'){
                    Table[i][j] = '*';
                    cpy.push({i,j});
                }
            }
        }
        while(!cpy.empty()){
            qW.push(cpy.front());
            cpy.pop();
        }
        bool Move = false;
        while(!qS.empty()){
            pair<int,int> u = qS.front();
            qS.pop();
            for(auto v : adj[u.first][u.second]){
                int i = v.first , j = v.second;
                if(Table[i][j] == 'D'){
                    printf("%d",walk+1);
                    return 0;
                }
                if(Table[i][j] == '.'){
                    Table[i][j] = 'S';
                    Move = true;
                    cpy.push({i,j});
                }
            }
        }
        if(!Move){
            printf("KAKTUS");
            return 0;
        }
        while(!cpy.empty()){
            qS.push(cpy.front());
            cpy.pop();
        }
        walk++;
    }
    return 0;
}

