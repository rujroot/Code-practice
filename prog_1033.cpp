/*  1033 : Conquerer
    ST : 18.05 25/4/2563 ED : 18.57 25/4/63
    O(n^2)
    Rujroot*/

#include <bits/stdc++.h>
using namespace std;
    vector<char> Player[10];
    pair<int,int> Position[10];
    int Table[150][150],Score[10];
bool standing(int i,int j){
    if((Position[0].first == i and Position[0].second == j) or (Position[1].first == i and Position[1].second == j) or (Position[2].first == i and Position[2].second == j) or (Position[3].first == i and Position[3].second == j)){
        return true;
    }
    return false;
}
int main()
{
    int n,walk;
    scanf("%d %d",&n,&walk);
    Table[0][0] = 4;
    Table[0][n-1] = 1;
    Table[n-1][0] = 3;
    Table[n-1][n-1] = 2;
    Position[0] = {0,n-1};
    Position[1] = {n-1,n-1};
    Position[2] = {n-1,0};
    Position[3] = {0,0};
    char path;
    for(int i=0;i<4;++i){
        for(int j=0;j<walk;++j){
            scanf(" %c",&path);
            Player[i].push_back(path);

        }
    }
    for(int i=0;i<walk;++i){
        for(int j=0;j<4;++j){
            path = Player[j][i];
            int Poi=Position[j].first,Poj=Position[j].second;
            if(path == 'S' and Poi+1 < n and !standing(Poi+1,Poj)){
                Table[Poi+1][Poj] = j+1;
                Position[j] = {Poi+1,Poj};
            }
            else if(path == 'W' and Poj-1 >= 0 and !standing(Poi,Poj-1)){
                Table[Poi][Poj-1] = j+1;
                Position[j] = {Poi,Poj-1};
            }
            else if(path == 'N' and Poi-1 >= 0 and !standing(Poi-1,Poj)){
                Table[Poi-1][Poj] = j+1;
                Position[j] = {Poi-1,Poj};
            }
            else if(path == 'E' and Poj+1 < n and !standing(Poi,Poj+1)){
                Table[Poi][Poj+1] = j+1;
                Position[j] = {Poi,Poj+1};
            }
        }

    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(Table[i][j] == 0){
                printf("No");
                return 0;
            }else{
                Score[Table[i][j]]++;
            }
        }
    }
    int Max = max(Score[1],max(Score[2],max(Score[3],Score[4]))),co=0;
    for(int i=1;i<=4;++i){
        if(Score[i] == Max)
            co++;
    }
    printf("%d %d\n",co,Max);
    for(int i=1;i<=4;++i){
        if(Score[i] == Max)
            printf("%d\n",i);
    }
    return 0;
}

