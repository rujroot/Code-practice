/*
    ST : 20.33
    ED : 20.48
*/
#include <bits/stdc++.h>
using namespace std;
bool Use[110];
int main()
{
    int n, arr[15][15];

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &arr[i][j]);
            Use[arr[i][j]] = true;
        }
    }
    for(int i = 1; i <= n*n; ++i){
        if(!Use[i]){
            printf("No");
            return 0;
        }
    }
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[0][i];
    }

    for(int i = 0; i < n; ++i){
        int sumc = 0, sumr = 0;

        for(int j = 0; j < n; j++){
            sumc += arr[i][j];
            sumr += arr[j][i];
        }

        if(sumc != sum or sumr != sum){
            printf("No");
            return 0;
        }
    }

    int sumd = 0;
    for(int i = 0; i < n; ++i){
        sumd += arr[i][i];
    }
    if(sumd != sum){
        printf("No");
        return 0;
    }
    sumd = 0;
    for(int i = 0; i < n; ++i){
        sumd += arr[i][n - i - 1];
    }
    if(sumd != sum){
        printf("No");
        return 0;
    }
    printf("Yes");
    return 0;
}
