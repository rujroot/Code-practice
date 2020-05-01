/*  1044 : Road Cut
    ST : 12.31 1/5/2563 ED : 13.34 1/5/2563
    O(n^3)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,sum,Max = -2e9,tmp[110][110],Teedin[110][110],ValTeedin[110][110],path,ij;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&Teedin[i][j]);
            tmp[i][j] = Teedin[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&ValTeedin[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            Teedin[i][j] = 0;
            if(i-1 >= 0){
                Teedin[i-1][j] += ValTeedin[i-1][j];
            }
            if(i+1 < n){
                Teedin[i+1][j] += ValTeedin[i+1][j];
            }
        }
        sum = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                sum += Teedin[i][j];
                Teedin[i][j] = tmp[i][j];
            }
        }
            Max = max(sum,Max);
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            Teedin[j][i] = 0;
            if(i-1 >= 0){
                Teedin[j][i-1] += ValTeedin[j][i-1];
            }
            if(i+1 < m){
                Teedin[j][i+1] += ValTeedin[j][i+1];
            }
        }
        sum = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                sum += Teedin[i][j];
                Teedin[i][j] = tmp[i][j];
            }
        }
        Max = max(sum,Max);
    }
    printf("%d",Max);
    return 0;
}

