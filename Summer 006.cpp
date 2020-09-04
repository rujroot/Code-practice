#include <bits/stdc++.h>

using namespace std;

char Main[5][5], C[5][5];

int Find(int i, int j, char F){
    //printf("in");
    for (int x = 0; x < 4; ++x){
        for(int y = 0; y < 4; ++y){
            if(C[x][y] == F){
                   // printf("%d %d %d %d\n",i,x,j,y);
                return abs(i - x) + abs(j - y);
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            scanf("%c", &C[i][j]);
        }getchar();
    }

    int n = 0;
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            Main[i][j] = 'A' + n;
            n++;
        }
    }
    Main[3][3] = '.';

    int Ans = 0;
    for (int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(Main[i][j] != C[i][j] and !(i == 3 and j == 3)){
                Ans += Find(i , j, Main[i][j]);
            }
        }
    }
    printf("%d",Ans);
   /* for(int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            printf("%c",C[i][j]);
        }
        //getchar();
        printf("\n");
    }*/
    return 0;
}
