/*  1067 : field
    ST : 19.55 22/5/2563 ED : 20.17 22/5/63
    O(n^3);
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int sanumparang[110][110],K,N,M,x,y,curr,visited[110][110],Ans;
int Find(int i,int j){
    if(i < 0 or i >= M or j < 0 or j >= N){
        return curr;
    }
    if(visited[i][j]){
        return 0;
    }
    visited[i][j] = true;
    curr = sanumparang[i][j];
    if(curr == 1){
        return Find(i-1,j);
    }else if(curr == 2){
         return Find(i,j+1);
    }else if(curr == 3){
         return Find(i+1,j);
    }else if(curr == 4){
         return Find(i,j-1);
    }
}
int main()
{
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            scanf("%d",&sanumparang[i][j]);
        }
    }
    for(int i=0;i<K;++i){
        scanf("%d %d",&x,&y);
        curr = 0;
        Ans = Find(y-1,x-1);
        if(Ans == 0)
            printf("NO\n");
        else if(Ans == 1)
            printf("N\n");
        else if(Ans == 2)
            printf("E\n");
        else if(Ans == 3)
            printf("S\n");
        else if(Ans == 4)
            printf("W\n");
        for(int k=0;k<N;++k){
            for(int l=0;l<M;++l){
                visited[k][l] = false;
            }
        }

    }
    return 0;
}

