#include <bits/stdc++.h>
using namespace std;
char Tarang[10][20];
int score = 0;
void Move(int x,int y,char z){
    char remem = Tarang[x][y];
    if(z == 'L'){
        Tarang[x][y] = '-';
        Tarang[x][y-2] = remem;
    }else{
        Tarang[x][y] = '-';
        Tarang[x][y+2] = remem;
    }
}
void gavity(int num1,int num2){
    for(int i=0;i<num1;++i){
        for(int j=0;j<num2;++j){
            if((Tarang[i][j] >= 65 and Tarang[i][j] <= 90) and Tarang[i+1][j] == '-'){
                char rem = Tarang[i][j];
                Tarang[i][j] = '-';
                for(int k=1;k<num1;++k){
                    if(i+k >= num1 or Tarang[i+k][j] != '-'){
                        Tarang[i+k-1][j] = rem;
                        gavity(num1,num2);
                        break;
                    }
                }
            }
        }
    }
}
void ch(int i,int j,char a){
    Tarang[i][j] = '-';
    score += 5;
    if(Tarang[i][j-2] == a) ch(i,j-2,a);
    if(Tarang[i][j+2] == a) ch(i,j+2,a);
    if(Tarang[i+1][j] == a) ch(i+1,j,a);
    if(Tarang[i-1][j] == a) ch(i-1,j,a);
}
int main()
{
    int ro,ca,num;
    scanf("%d %d ",&ca,&ro);
    for(int i=0;i<ca;++i){
        for(int j=0;j<ro*2-1;++j){
            scanf("%c",&Tarang[i][j]);
        }
        getchar();
    }
    pair<pair<int,int>,char> p[30];
    scanf("%d",&num);
    int x,y;
    char z;
    for(int i=0;i<num;++i){
        scanf("%d %d ",&x,&y);
        scanf("%c",&z);
        p[i] = {{x,y},z};
    }
    for(int i=0;i<num;++i){
        x = p[i].first.first;
        y = p[i].first.second*2;
        z = p[i].second;
        if(Tarang[x][y] == '#' || Tarang[x][y] == '-' || !(Tarang[x][y] >= 65 and Tarang[x][y] <= 90)){
            score -= 5;
        }
        else if(z == 'L' and Tarang[x][y-2] != '-'){
            score -= 5;
        }
        else if(z == 'R' and Tarang[x][y+2] != '-'){
            score -= 5;
        }else{
            Move(x,y,z);
            gavity(ca,ro*2-1);
            for(int i=0;i<ca;++i){
                for(int j=0;j<ro*2-1;++j){
                    if((Tarang[i][j] >= 65 and Tarang[i][j] <= 90) and (Tarang[i][j-2] == Tarang[i][j] or Tarang[i][j-2] == Tarang[i][j] or Tarang[i+1][j] == Tarang[i][j] or Tarang[i-1][j] == Tarang[i][j] )){
                        ch(i,j,Tarang[i][j]);
                        gavity(ca,ro*2-1);
                    }
                }
            }
        }
    }
    for(int i=0;i<ca;++i){
        for(int j=0;j<ro*2-1;++j){
            if((Tarang[i][j] >= 65 and Tarang[i][j] <= 90) and (Tarang[i][j-2] == Tarang[i][j] or Tarang[i][j-2] == Tarang[i][j] or Tarang[i+1][j] == Tarang[i][j] or Tarang[i-1][j] == Tarang[i][j] )){
                ch(i,j,Tarang[i][j]);
                gavity(ca,ro*2-1);
                }
            }
        }
    printf("%d\n",score);
    for(int i=0;i<ca;++i){
        for(int j=0;j<ro*2-1;++j){
            printf("%c",Tarang[i][j]);
        }
        printf("\n");
    }

    return 0;
}
