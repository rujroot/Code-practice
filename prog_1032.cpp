/*  1032 : Sudoku
    ST : 16.56 ED : 18.28
    O(n^3)
    Rujroot
    */
#include <bits/stdc++.h>
using namespace std;
int Main[20][20],CCAL[20][20],CROW[20][20],Ans[20][20],C9x9[20][20];
bool Ch(int ans[20][20]){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(Main[i][j] != 0 and ans[i][j] != Main[i][j])
                return false;
            CCAL[i][j] = 0;
            CROW[i][j] = 0;
            C9x9[i][j] = 0;
        }
    }
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(CROW[i][ans[i][j]-1] == 0)
                CROW[i][ans[i][j]-1]++;
            else
                return false;
        }
    }
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(CCAL[i][ans[j][i]-1] == 0)
                CCAL[i][ans[j][i]-1]++;
            else
                return false;
        }
    }
    for(int i=0;i<9;++i){
        int poi=i/3,poj=i%3;
        for(int j=0;j<3;++j){
            for(int k=0;k<3;++k){
                if(C9x9[i][ans[(poi*3)+j][(poi*3)+k]-1] == 0)
                    C9x9[i][ans[(poi*3)+j][(poi*3)+k]-1]++;
                else
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    int n,x;
    scanf("%d",&n);
    bool Wrong;
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            scanf("%d",&Main[i][j]);
        }
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                scanf("%d",&Ans[i][j]);
            }
        }
        if(Ch(Ans)){
            printf("%d\n",k+1);
        }
    }
    printf("END");
    return 0;
}
//-----<Comment>------//

