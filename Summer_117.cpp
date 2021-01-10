#include<bits/stdc++.h>
using namespace std;

int DP[20][20];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= 10; ++i){
        DP[1][i] = 1;
    }

    for(int i = 2; i <= n; ++i){
        for(int j = 0; j <= 9; ++j){
            if(j == 0)
                DP[i][j] = DP[i - 1][j] + DP[i - 1][8];
            if(j == 1)
                DP[i][j] = DP[i - 1][j] + DP[i - 1][2] + DP[i - 1][4];
            if(j == 2)
                DP[i][j] = DP[i - 1][j] + DP[i - 1][1] + DP[i - 1][3] + DP[i - 1][5];
            if(j == 3)
                DP[i][j] = DP[i - 1][j] + DP[i - 1][2] + DP[i - 1][6];
            if(j == 4)
                DP[i][j] = DP[i - 1][j] + DP[i - 1][1] + DP[i - 1][5] + DP[i - 1][7];
            if(j == 5)
                DP[i][j] = DP[i - 1][j] + DP[i - 1][2] + DP[i - 1][4] + DP[i - 1][6] + DP[i - 1][8];
            if(j == 6)
                DP[i][j] = DP[i - 1][j] + DP[i - 1][3] + DP[i - 1][5] + DP[i - 1][9];
            if(j == 7)
                DP[i][j] = DP[i - 1][j] + DP[i - 1][4] + DP[i - 1][8];
            if(j == 8)
                DP[i][j] = DP[i - 1][j] + DP[i - 1][5] + DP[i - 1][7] + DP[i - 1][9] + DP[i - 1][0];
            if(j == 9)
                DP[i][j] = DP[i - 1][j] + DP[i - 1][8] + DP[i - 1][6];

        }
    }

    int sum = 0;
    for(int i = 0; i <= 9; ++i)
        sum += DP[n][i];
    
    printf("%d", sum);

}