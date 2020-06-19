/*  1095 : 
    ST : 21.42 19/6/63
    Read : 21.42 - 21.45 : 3 Min
    ED : 1.34 20/6/63
    Total :
    O(n^2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int R,C,Rotate;
char ans[1000][1000],s[15][15];
int main()
{

    scanf("%d %d ",&R,&C);
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            scanf("%c",&s[i][j]);
        }getchar();
    }
    for(int i=0;i<500;++i){
        for(int j=0;j<500;++j){
            ans[i][j] = ' ';
        }
    }
    scanf("%d",&Rotate);
    if(Rotate == 0 or Rotate == 360){
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                printf("%c",s[i][j]);
            }if(i != R-1)printf("\n");
        }
    }
    else if(Rotate == 90){
        for(int i=0;i<C;++i){
            for(int j=R-1;j>=0;--j){
                printf("%c",s[j][i]);
            }if(i != C-1)printf("\n");
        }
    }
    else if(Rotate == 180){
        for(int i=R-1;i>=0;--i){
            for(int j=C-1;j>=0;--j){
                printf("%c",s[i][j]);
            }if(i != 0)printf("\n");
        }
    }
    else if(Rotate == 270){
        for(int i=C-1;i>=0;--i){
            for(int j=0;j<R;++j){
                printf("%c",s[j][i]);
            }if(i != 0)printf("\n");
        }
    }
    if(Rotate == 45){
        int line = 0,st = R-1;
        for(int i=0;i<C;++i){
            for(int j=0;j<R;++j){
                ans[line+j][st-j] = s[j][i];
            }
            line++;
            st++;
        }
        int l = R,Round = 1;
        for(int i=0;i<R+C-1;++i){
            for(int j=0;j<l;++j){
                printf("%c",ans[i][j]);
            }
            if(i != R+C-2)
                printf("\n");
            if(Round > C-1){
                l--;
            }
            else{
                Round++;
                l++;
            }
        }
    }
    else if(Rotate == 315){
        int line = C-1,st = 0;
        for(int i=0;i<R;++i){
            for(int j=C-1;j>=0;--j){
                ans[line-j][j+st] = s[i][j];
            }
            line++;
            st++;
        }
        int l = C,Round = 1;
        for(int i=0;i<C+R-1;++i){
            for(int j=0;j<l;++j){
                printf("%c",ans[i][j]);
            }
            if(i != C+R-2)
                printf("\n");
            if(Round > R-1){
                l--;
            }
            else{
                Round++;
                l++;
            }
        }
    }else if(Rotate == 135){
        int line = 0,st = C-1;
        for(int i=R-1;i>=0;--i){
            for(int j=0;j<C;++j){
                ans[line+j][st-j] = s[i][j];
            }
            st++;
            line++;
        }
        int l = C,Round = 1;
        for(int i=0;i<C+R-1;++i){
            for(int j=0;j<l;++j){
                printf("%c",ans[i][j]);
            }
            if(i != C+R-2)
                printf("\n");
            if(Round > R-1){
                l--;
            }
            else{
                Round++;
                l++;
            }
        }
    }else if(Rotate == 225){
        int line = R-1,st = 0;
        for(int i=C-1;i>=0;--i){
            for(int j=R-1;j>=0;--j){
                ans[line-j][j+st] = s[j][i];
            }
            st++;
            line++;
        }
        int l = R,Round = 1;
        for(int i=0;i<C+R-1;++i){
            for(int j=0;j<l;++j){
                printf("%c",ans[i][j]);
            }
            if(i != C+R-2)
                printf("\n");
            if(Round > C-1){
                l--;
            }
            else{
                Round++;
                l++;
            }
        }
    }
    return 0;
}

