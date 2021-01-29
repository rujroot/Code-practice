#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, A[15][15], Max = -2e9;
    vector<int> po;
    vector<pair<int, int> > Ans;

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            scanf("%d", &A[i][j]);
        }
        po.push_back(i);
    }

    do{
        int sum = 0, i = 1;
        vector<pair<int, int> > v;

        for(int j = 0; j < n; ++j){
            sum += A[i][po[j]];
            v.push_back({i, po[j]});
            i++;
        }

        if(sum > Max){
            Max = sum;
            Ans = v;
        }

    }while(next_permutation(po.begin(), po.end()));
    
    printf("%d\n", Max);
    for(int i = 0; i < Ans.size(); ++i){
        printf("%d %d\n", Ans[i].first, Ans[i].second);
    }


    return 0;
}
