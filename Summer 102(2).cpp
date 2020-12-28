#include<bits/stdc++.h>
using namespace std;

int a[110][110];
unsigned long long int  cur[110][10100], prv[110][10100], Ans[10100];
bool Ask[10100];
vector<int> v;

int main(){
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int x; scanf("%d", &x);
            a[i][j] = x;
        }
    }
    for(int i = 0;i < t; ++i){
        int x; scanf("%d", &x);
        Ask[x] = true;
        v.push_back(x);
    }

    cur[1][a[1][1]] = 1;
    for(int j = 1; j <= m; ++j){
        for(int k = 1; k < 10100; ++k){
            if(j - 1 <= 0)
                continue;
            if(k - a[1][j] < 0)
                continue;
            cur[j][k] = cur[j - 1][k - a[1][j]];
        }  
    }

    for(int i = 2; i <= n; ++i){

        for(int j = 1; j <= m; ++j){
            for(int k = 1; k < 10100; ++k){
                prv[j][k] = cur[j][k];
                cur[j][k] = 0;
            }
        }

        for(int j = 1; j <= m; ++j){
            for(int k = 1; k < 10100; ++k){
                if(k - a[i][j] < 0)
                    continue;
                else if(j - 1 <= 0)
                    cur[j][k] = prv[j][k - a[i][j]];
                else
                    cur[j][k] = cur[j - 1][k - a[i][j]] + prv[j][k - a[i][j]];

                if(i == n and j == m and Ask[k]){
                    //printf("-->%d %d\n", k, cur[j][k]);
                    Ans[k] = cur[j][k]; 
                } 

            }
        }
        
    }

    for(int i = 0; i < v.size(); ++i){
        if(v[i] < 0)
            printf("0\n");
        else
         printf("%lu\n", Ans[v[i]]);
    }

}
