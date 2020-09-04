#include <bits/stdc++.h>
using namespace std;
char Ans[505][505];
int n;
void rightend(int i,int j,char s){
    while(j <= n and Ans[i][j] == '.'){
       Ans[i][j] = s;
       j++;
    }
}

void up(int i,int j,char s){
    while(i >= 0 and Ans[i-1][j] == '.'){
       Ans[i][j] = s;
       i--;
    }
    rightend(i,j,s);
}

void left(int i,int j,char s){
    while(j >= 0 and Ans[i][j-1] == '.')
    {
       Ans[i][j] = s;
       j--;
    }
    up(i,j,s);
}

void down(int i,int j,char s){
    while(i <= n and Ans[i+1][j] == '.')
    {
       Ans[i][j] = s;
       i++;
    }
    left(i,j,s);
}

void right(int i,int j,char s){
    while(j <= n and Ans[i][j+1] == '.'){
        Ans[i][j] = s;
       j++;
    }
    down(i,j,s);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            Ans[i][j] = '.';
        }
    }

    for(int i=0;i<(n+1)/2;++i){
        if(i%2 == 0)
            right(i,n/2,'*');
        else
            right(i,n/2,'-');
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            printf("%c",Ans[i][j]);
        }printf("\n");
    }
    return 0;
}
