/*  1092 : general

    ST : 8.08 17/6/63
    Read : 8.08 - 8.17 : 10 Min
    ED : 8.48
    Total : 41 Min

    O(M) ??? O(M log n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int N,M,x,y,Win,Lx,Ly;
vector<int> Army,Leader;
int FindLeader(int n){
    while(Leader[n] != n){
        n = Leader[n];
    }
    return n;
}
int main()
{

    Army.push_back(0);
    Leader.push_back(0);
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;++i){
        scanf("%d",&x);
        Army.push_back(x);
        Leader.push_back(i);
    }
    for(int i=1;i<=M;++i){
        scanf("%d %d",&x,&y);
        Lx = FindLeader(x);
        Ly = FindLeader(y);
        if(Lx == Ly){
            printf("-1\n");
            continue;
        }
        if(Army[Lx] == Army[Ly]){
            if(Lx  > Ly){
                printf("%d\n",Ly);
                Army[Ly] += Army[Lx]/2;
                Leader[Lx] = Ly;
            }else{
                printf("%d\n",Lx);
                Army[Lx] += Army[Ly]/2;
                Leader[Ly] = Lx;
            }
        }else if(Army[Lx] > Army[Ly]){
            printf("%d\n",Lx);
            Army[Lx] += Army[Ly]/2;
            Leader[Ly] = Lx;

        }else{
            printf("%d\n",Ly);
            Army[Ly] += Army[Lx]/2;
            Leader[Lx] = Ly;
        }
    }
    return 0;
}

