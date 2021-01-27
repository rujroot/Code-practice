#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    double A[5][5];
    scanf("%d %d", &n , &m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%lf", &A[i][j]);
        }
    }

    double Ans = 0;
    for(int i = 1; i <= n * m; ++i){

        int poi, poj;
        double Min = 18e9;

        for(int i = 1; i <= n ; ++i){
            for(int j = 1; j <= m; ++j){
                if(Min > A[i][j]){
                    poi = i;
                    poj = j;
                    Min = A[i][j];
                }
            }
        }

        Ans += Min;
        A[poi + 1][poj + 1] += A[poi][poj] * 0.1;
        A[poi + 1][poj] += A[poi][poj] * 0.1;
        A[poi + 1][poj - 1] += A[poi][poj] * 0.1;
        A[poi][poj + 1] += A[poi][poj] * 0.1;
        A[poi][poj - 1] += A[poi][poj] * 0.1;
        A[poi - 1][poj + 1] += A[poi][poj] * 0.1;
        A[poi - 1][poj] += A[poi][poj] * 0.1;
        A[poi - 1][poj + 1] += A[poi][poj] * 0.1;
        A[poi][poj] = 18e9;

    }
    
    printf("%.2f", Ans);
    

}
