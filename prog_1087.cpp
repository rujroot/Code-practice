/*  1087 : house
    ST : 17.00 12/6/63 ED : 19.18 12/6/63
    O(R*C*K)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int Table[310][310],R,C,K,Max = 0,Happy;
    scanf("%d %d %d",&R,&C,&K);
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            scanf("%d",&Table[i][j]);
        }
    }
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            Happy = 0;
            for(int U = max(0,i-K);U <= min(R-1,i+K);++U){
                if((max(i,U) - min(i,U))% 2 == 0){
                    Happy += Table[U][j];
                }else{
                    Happy -= Table[U][j];
                }
            }
            for(int D = max(0,j-K);D <= min(C-1,j+K);++D){
                if((max(j,D) - min(j,D))% 2 == 0){
                    Happy += Table[i][D];
                }else{
                    Happy -= Table[i][D];
                }
            }
            Happy -= Table[i][j];
            Max = max(Max,Happy);
        }
    }
    printf("%d",Max);
    return 0;
}

