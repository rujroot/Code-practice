/*  1038 : Bond
    ST : 17.24 3/5/2563 ED : 17.44 3/5/2563
    O(n^2)
    Rujroot
 */
#include <bits/stdc++.h>
using namespace std;
int n;
double Ch[21][21],Mem[1<<21];
bool visited[1<<21];
double dp(int i,int pick){
    if(i == n+1)
        return 1;
    if(visited[pick])
        return Mem[pick];
    double mx = 0;
    for(int j=1;j<=n;++j){
        if((pick&(1<<j)) != 0)
            continue;
        mx = max(mx,Ch[i][j] * dp(i+1,pick|(1<<j)));
    }
    visited[pick] = true;
    Mem[pick] = mx;
    return mx;
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%lf",&Ch[i][j]);
            Ch[i][j] /= 100.0;
        }
    }
    printf("%.6f",dp(1,0)*100.0);
    return 0;
}

