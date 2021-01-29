#include<bits/stdc++.h>
using namespace std;

int n, A[15][15], Max = -2e9;
vector<pair<int, int> > v;

int Rook(bool C[15], int sum, int i, int j, vector<pair<int, int> > po){

    if(C[j])
        return 0;

    if(i > n){
        if(sum > Max){
            v = po;
            Max = sum;
        }
        return 0;
    }

    if(A[i][j] > 0){
        sum += A[i][j];
        C[j] = true;
        po.push_back({i, j});
    }

    vector<pair<int, int> > Savepo;
    bool SaveC[15];

    for(int a = 1; a <= n; ++a){
        SaveC[a] = C[a];
    }
    Savepo = po;

    for(int j = 1; j <= n; ++j){
        Rook(C, sum, i + 1, j, po);

        for(int a = 1; a <= n; ++a){
            C[a] = SaveC[a];
        }
        po = Savepo;
    }

}

int main(){
    
    bool C[15];
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            scanf("%d", &A[i][j]);
        }
        C[i] = false;
    }

    
    for(int i = 1; i <= n; ++i){
        vector<pair<int, int> > p;
        Rook(C, 0, 1, i, p);
        for(int a = 1; a <= n; ++a){
            C[a] = false;
        }
    }

    printf("%d\n", Max);
    for(int i = 0; i < v.size(); ++i){
        printf("%d %d\n", v[i].first, v[i].second);
    }

}