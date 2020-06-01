/*  1077 : Key
    ST : 9.53 1/6/63 ED : 23.45 1/6/63
	O(M)
    rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int N,M,x,y,z,XP,XM,YP,YM;
int Table[1010][1010];
int main()
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;++i){
        scanf("%d %d",&x,&y);
        Table[x+1][y+1]++;
    }
    for(int i=1;i<1010;++i){
        for(int j=1;j<1010;++j){
            Table[i][j] += Table[i-1][j] + Table[i][j-1] - Table[i-1][j-1];
        }
    }
    for(int j=0;j<M;++j){
        scanf("%d %d %d",&x,&y,&z);
        x++;
        y++;
        XP = x+z;
        XM = x-z;
        YP = y+z;
        YM = y-z;
        if(XP > 1001)
            XP = 1001;
        if(YP > 1001)
            YP = 1001;
        if(XM < 1)
            XM = 1;
        if(YM < 1)
            YM = 1;
        printf("%d\n",Table[XP][YP] - Table[XM-1][YP] - Table[XP][YM-1] + Table[XM-1][YM-1]);
    }
    return 0;
}
