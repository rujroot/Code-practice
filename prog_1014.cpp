
#include <bits/stdc++.h>
using namespace std;
int paman[10000];
int main()
{
    int W,H,n,x,y,s0=0,s50=0;
    scanf("%d %d %d",&W,&H,&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x,&y);
        for(int j=x;j<x+y;++j){
            if(j < W){
                paman[j]++;
            }
        }
    }
    for(int i=0;i<W;++i){
        if(paman[i] == 0){
            s0++;
        }else if(paman[i] == 1){
            s50++;
            }
        }
    printf("%d %d",s0*H,s50*H);
    return 0;
}

