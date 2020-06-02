/*  1058 : Longest
    ST : 22.45 17/5/2563 ST : 22.46 2/6/63
    O(n^3)
    rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int K,M,N,Max = 0;
char Table[1010][1010];
int L[1010][1010],R[1010][1010],D[1010][1010],U[1010][1010];
int main()
{
    scanf("%d",&K);
    for(int k=0;k<K;++k){
        scanf("%d %d",&N,&M);
        getchar();
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                scanf("%c",&Table[i][j]);
                if(Table[i][j] == '1'){
                    L[i][j] = L[i][j-1] + 1;
                    D[i][j] = D[i-1][j] + 1;
                }
            }
            getchar();
        }
        for(int i=N;i>=1;--i){
            for(int j=M;j>=1;--j){
                if(Table[i][j] == '1'){
                    R[i][j] = R[i][j+1] + 1;
                    U[i][j] = U[i+1][j] + 1;
                }
            }
        }
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                if(L[i][j] != 1 and L[i][j] != 0){
                    Max = max(Max,L[i][j] + max(U[i][j],D[i][j]) - 1);
                }
                if(R[i][j] != 1 and R[i][j] != 0){
                    Max = max(Max,R[i][j] + max(U[i][j],D[i][j]) - 1);
                }
                if(D[i][j] != 1 and D[i][j] != 0){
                    Max = max(Max,D[i][j] + max(L[i][j],R[i][j]) - 1);
                }
                if(U[i][j] != 1 and U[i][j] != 0){
                    Max = max(Max,U[i][j] + max(L[i][j],R[i][j]) - 1);
                }
            }
        }
        printf("%d\n",Max);
        Max = 0;
        for(int i=0;i<=N+1;++i){
            for(int j=0;j<=M+1;++j){
                L[i][j] = 0;
                R[i][j] = 0;
                D[i][j] = 0;
                U[i][j] = 0;
            }
        }
    }
    return 0;
}

