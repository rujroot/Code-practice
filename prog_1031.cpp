/*  1031 : Tower
    ST : 13.02 27/4/2563 ED : 23.50 5/5/2563
    O(n + i);
    Rujroot
*/
#include <stdio.h>
#include <vector>
using namespace std;
int Power,N,num,x,y,Mem[10010];
vector<int> adj[10010];
int DP(int floor){
    if(floor == 1)
        return 0;
    if(Mem[floor] != 0)
        return Mem[floor];
    if(adj[floor].empty())
        return 2e9;
    Mem[floor] = 2e9;
    for(auto v: adj[floor]){
        Mem[floor] = min(Mem[floor],DP(v)+1);
    }
    return Mem[floor];
}
int main(){
    scanf("%d %d %d",&Power,&N,&num);
    for(int i=1;i<=num;++i){
        scanf("%d %d",&x,&y);
        adj[y].push_back(x);
    }
    for(int i=N;i>=1;--i){
      DP(i);
    }
    for(int i=N;i>=1;--i){
        if(Mem[i] != 0 and Mem[i] <= Power){
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}

