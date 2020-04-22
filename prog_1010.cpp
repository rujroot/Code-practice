#include <bits/stdc++.h>
using namespace std;
string Find[110];
pair<int,int> Ans[110];
char Info[30][30];
int num1,num2,num3,ck=0,tmp=0;
void GL(int i,int j,int c){
    for(int k=0;k<Find[c].size();++k){
        if(j+k >= num2 || Find[c][k] != Info[i][j+k]){
            break;
        }else{
            ck++;
            }
        }
        if(ck > tmp){
            tmp = ck;
            ck = 0;
            Ans[c] = {i,j};
        }else{
            ck = 0;
    }
}
void GDL(int i,int j,int c){
    for(int k=0;k<Find[c].size();++k){
        if(i-k < 0 || j+k >= num2 || Find[c][k] != Info[i-k][j+k]){
            break;
        }else{
            ck++;
        }
    }
    if(ck > tmp){
        tmp = ck;
        ck = 0;
        Ans[c] = {i,j};
    }else{
        ck=0;
    }
}
void GD(int i,int j,int c){
    for(int k=0;k<Find[c].size();++k){
        if(i-k < 0 || Find[c][k] != Info[i-k][j]){
            break;
        }else{
            ck++;
        }
    }
    if(ck > tmp){
        tmp = ck;
        ck = 0;
        Ans[c] = {i,j};
    }else{
        ck=0;
    }
}
void GDR(int i,int j,int c){
    for(int k=0;k<Find[c].size();++k){
        if(j-k < 0 ||i-k < 0 ||Find[c][k] != Info[i-k][j-k]){
            break;
        }else{
            ck++;
        }
    }
    if(ck > tmp){
        tmp = ck;
        ck = 0;
        Ans[c] = {i,j};
    }else{
        ck=0;
    }
}
void GR(int i,int j,int c){
    for(int k=0;k<Find[c].size();++k){
        if(j-k < 0 || Find[c][k] != Info[i][j-k]){
            break;
        }else{
            ck++;
        }
    }
    if(ck > tmp){
        tmp = ck;
        ck = 0;
        Ans[c] = {i,j};
    }else{
        ck=0;
    }
}
void GUR(int i,int j,int c){
    for(int k=0;k<Find[c].size();++k){
        if(i+k >= num1 || j-k < 0 || Find[c][k] != Info[i+k][j-k]){
            break;
        }else{
            ck++;
        }
    }
    if(ck > tmp){
        tmp = ck;
        ck = 0;
        Ans[c] = {i,j};
    }else{
        ck=0;
    }
}
void GU(int i,int j,int c){
    for(int k=0;k<Find[c].size();++k){
        if(i+k >= num1 || Find[c][k] != Info[i+k][j]){
            break;
        }else{
            ck++;
        }
    }
    if(ck > tmp){
        tmp = ck;
        ck = 0;
        Ans[c] = {i,j};
    }else{
        ck=0;
    }
}
void GUL(int i,int j,int c){
    for(int k=0;k<Find[c].size();++k){
        if(i+k >= num1 || j+k >= num2 || Find[c][k] != Info[i+k][j+k]){
            break;
        }else{
            ck++;
        }
    }
    if(ck > tmp){
        tmp = ck;
        ck = 0;
        Ans[c] = {i,j};
    }else{
        ck=0;
    }
}
int main()
{
    //printf("%d %d",'a','z');
    scanf("%d %d ",&num1,&num2);
    for(int i=0;i<num1;++i){
        for(int j=0;j<num2;++j){
            scanf("%c",&Info[i][j]);
            if(Info[i][j] >= 65 && Info[i][j] <= 90){
                Info[i][j] += 32;
            }
        }
        getchar();
    }
    scanf("%d",&num3);
    for(int i=0;i<num3;++i){
        cin >> Find[i];
        for(int j=0;j<Find[i].size();++j){
            if(Find[i][j] >= 65 && Find[i][j] <= 90){
                Find[i][j] += 32;
            }
        }
    }
    for(int i=0;i<num3;++i){
        ck = 0;
        tmp = 0;
        for(int j=0;j<num1;++j){
            for(int k=0;k<num2;++k){
                if(Find[i][0] == Info[j][k]){
                          //printf("i = %d ck = %d tmp = %d\n",i,ck,tmp);
                           // if(k+1 < num2 && Find[i][1] == Info[j][k+1]){
                                GL(j,k,i);
                            //}
                           if(j-1 >= 0 && k+1 < num2  && Find[i][1] == Info[j-1][k+1]){
                                GDL(j,k,i);
                            }
                            if(j-1 >= 0 && Find[i][1] == Info[j-1][k]){
                                GD(j,k,i);
                            }
                            if(j-1 >= 0 && k-1 >= 0 && Find[i][1] == Info[j-1][k-1]){
                                GDR(j,k,i);
                            }
                            if(k-1 >= 0 && Find[i][1] == Info[j][k-1]){
                                GR(j,k,i);
                            }
                            if(j+1 < num2 && k-1 >= 0 && Find[i][1] == Info[j+1][k-1]){
                                GUR(j,k,i);
                            }
                            if(j+1 < num2 && Find[i][1] == Info[j+1][k]){
                                GU(j,k,i);
                            }
                            if(j+1 < num2 && k+1 < num2 && Find[i][1] == Info[j+1][k+1]){
                                GUL(j,k,i);
                            }
                    /*for(int m=0;m<Find[i].size();++m){
                        if(Find[i][m] != Info[j][k+m]){
                            break;
                        }else{
                           ck++;
                        }
                    }
                    if(ck >= tmp){
                        tmp = ck;
                        ck = 0;
                        Ans[i] = {j,k};
                    }else{
                        ck = 0;
                    }*/
                }
            }
        }
    }
    for(int i=0;i<num3;++i){
        printf("%d %d\n",Ans[i].first,Ans[i].second);
    }
    /*printf("\n");
    for(int i=0;i<num1;++i){
        for(int j=0;j<num2;++j){
            printf("%c",Info[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<num3;++i){
        cout << Find[i] << "\n";
    }*/
    return 0;
}
