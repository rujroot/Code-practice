#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> v[50];
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<i+1;++j){
            if(j == 0){
                v[i].push_back(1);
            }else if(j == i){
                v[i].push_back(1);
            }else{
                v[i].push_back(v[i-1][j] + v[i-1][j-1]);
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<2*(n-i)+1;++j){
            printf("_");
        }
        for(int j=0;j<i+1;++j){
            if(j == i){
                printf("%d",v[i][j]);
            }
            else{
                printf("%d__",v[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
