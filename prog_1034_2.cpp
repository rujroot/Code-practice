#include <bits/stdc++.h>
using namespace std;
int Table[10][10],Turn = -1;
bool ch(int x,int y){
    bool Have = false;
    for(int i=x+1;i<8;++i){
        if(Table[y][i] == 0){
           break;
        }else if(Table[y][i] == Turn){
            Have = true;
            for(int j=x+1;j<i;++j)
                Table[y][j] = Turn;
            break;
        }
    }
    for(int i=1;i<8;++i){
        if(y+i > 8 or x+i > 8 or Table[y+i][x+i] == 0){
            break;
        }
        else if(Table[y+i][x+i] == Turn){
            Have = true;
            for(int j=1;j<i;++j){
                Table[y+j][x+j] = Turn;
            }

            break;
        }
    }
    for(int i=y+1;i<8;++i){
        if(Table[i][x] == 0){
            break;
        }
        else if(Table[i][x] == Turn){
            Have = true;
            for(int j=y;j<i;++j)
                Table[j][x] = Turn;
            break;
        }
    }
    for(int i=1;i<8;++i){
        if(y+i > 8 or x-i < 0 or Table[y+i][x-i] == 0){
            break;
        }
        else if(Table[y+i][x-i] == Turn){
            Have = true;
            for(int j=1;j<=i;++j)
                Table[y+j][x-j] = Turn;
            break;
        }
    }
    for(int i=x-1;i>=0;--i){
        if(Table[y][i] == 0){
            break;
        }
        else if(Table[y][i] == Turn){
            Have = true;
           for(int j=i;j<=x-1;++j)
                Table[y][j] = Turn;
           break;
        }
    }
    for(int i=1;i<8;++i){
        if(y-i < 0 or x-i < 0 or Table[y-i][x-i] == 0)
            break;
        else if(Table[y-i][x-i] == Turn){
            Have = true;
            for(int j = 1;j<i;++j)
                Table[y-j][x-j] = Turn;
            break;
        }
    }
    for(int i=y-1;i>=0;--i){
        if(Table[i][x] == 0){
            break;
        }
        else if(Table[i][x] == Turn){
            Have = true;
            for(int j=y-1;j>=i;--j)
                Table[j][x] = Turn;
            break;
        }
    }
    for(int i=1;i<8;++i){
        if(y-i < 0 or x+i > 8 or Table[y-i][x+i] == 0)
            break;
        else if(Table[y-i][x+i] == Turn){
            Have = true;
            for(int j=1;j<i;++j)
                Table[y-j][x+j] = Turn;
            break;
        }
    }
    return Have;
}
int main()
{
    Table[3][3] = 1;
    Table[3][4] = -1;
    Table[4][3] = -1;
    Table[4][4] = 1;
    int n,x,y;
    char po;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf(" %c",&po);
        scanf("%d",&y);
        y = y-1;
        x = po-97;
        Table[y][x] = Turn;
        ch(x,y);
        Turn = -(Turn);
    }
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            if(Table[i][j] == -1){
                printf("X");
            }else if(Table[i][j] == 1){
                printf("O");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}
