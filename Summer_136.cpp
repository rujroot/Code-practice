#include<bits/stdc++.h>
using namespace std;

int n, m;
double Ans = 9e18;

double Buy(double A[5][5], double sum, bool Land[5][5], int count, int po1, int po2){
    if(!Land[po1][po2]){
        Land[po1][po2] = true;
        sum += A[po1][po2];
        count++;
        A[po1 - 1][po2 - 1] += A[po1][po2] * 0.1;
        A[po1 - 1][po2] += A[po1][po2] * 0.1;
        A[po1 - 1][po2 + 1] += A[po1][po2] * 0.1;
        A[po1][po2 - 1] += A[po1][po2] * 0.1;
        A[po1][po2 + 1] += A[po1][po2] * 0.1;
        A[po1 + 1][po2 - 1] += A[po1][po2] * 0.1;
        A[po1 + 1][po2] += A[po1][po2] * 0.1;
        A[po1 + 1][po2 + 1] += A[po1][po2] * 0.1;
    }

    double  SaveA[5][5];
    bool SaveL[5][5];

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            SaveA[i][j] = A[i][j];
            SaveL[i][j] = Land[i][j];
        }
    }
    
    if(count == n*m){
        Ans = min(Ans, sum);
        return 0;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(!Land[i][j])
                Buy(A, sum, Land, count, i, j);

            for(int a = 1; a <= n; ++a){
                for(int b = 1; b <= m; ++b){
                    A[a][b] = SaveA[a][b];
                    Land[a][b] = SaveL[a][b];
                }
            }

        }
    }

}

int main(){
    scanf("%d %d", &n, &m);

    double Arr[5][5], Save[5][5];
    bool LandP[5][5];

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%lf", &Arr[i][j]);
            LandP[i][j] = false;
            Save[i][j] = Arr[i][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            Buy(Arr, 0, LandP, 0, i, j);

            for(int a = 1; a <= n; ++a){
                for(int b = 1; b <= m; ++b){
                    Arr[a][b] = Save[a][b];
                    LandP[a][b] = false;
                }
            }

        }
    }
    printf("%.2f", Ans);
    return 0;
}
