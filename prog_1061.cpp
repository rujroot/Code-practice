/*  1061 : Temperature is Rising
    ST : 18:18 14/5/63 ED : 18.35 14/5/63
    O(n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int MT[30][30],Max,N,Si,Sj;
bool Visited[30][30];
void Move(int i,int j){
    int curr = MT[i][j];
    if(!Visited[i][j]){
        Visited[i][j] = true;
        if(i+1 <= N and MT[i+1][j] != 100 and MT[i+1][j] > curr){
            Max = max(Max,MT[i+1][j]);
            Move(i+1,j);
        }
        if(i-1 >= 1 and MT[i-1][j] != 100 and MT[i-1][j] > curr){
            Max = max(Max,MT[i-1][j]);
            Move(i-1,j);
        }
        if(j+1 <= N and MT[i][j+1] != 100 and MT[i][j+1] > curr){
            Max = max(Max,MT[i][j+1]);
            Move(i,j+1);
        }
        if(j-1 >= 1 and MT[i][j-1] != 100 and MT[i][j-1] > curr){
            Max = max(Max,MT[i][j-1]);
            Move(i,j-1);
        }
    }
}
int main()
{
    scanf("%d %d %d",&N,&Sj,&Si);
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            scanf("%d",&MT[i][j]);
        }
    }
    Max = MT[Si][Sj];
    Move(Si,Sj);
    printf("%d",Max);
    return 0;
}

