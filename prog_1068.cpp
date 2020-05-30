/*  1068 : border
    ST : 14.00 30/5/63 ED : 15.51 30/5/63
    O(n ^ 2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,K,x,po = 0;
    scanf("%d %d",&N,&K);
    vector<vector<int>> v(10010);
    vector<int> value;
    for(int i=0;i<(N*2)+1;++i){
        if(i == 0 or i == N*2){
            for(int j=0;j<N;++j){
                scanf("%d",&x);
                v[po+j].push_back(x);
            }
        }else if(i % 2 == 0){
            for(int j=0;j<N;++j){
                scanf("%d",&x);
                v[po+N+j].push_back(x);
                v[po+j].push_back(x);
            }
        }else{
            for(int j=0;j<N+1;++j){
                scanf("%d",&x);
                if(j == 0){
                    v[po+j].push_back(x);
                }else if(j == N){
                    v[po+j-1].push_back(x);
                }else{
                    v[po+j].push_back(x);
                    v[po+j-1].push_back(x);
                }
            }
        }
        if(i != 0 and i % 2 == 0)
            po += N;
    }
    for(int i=0;i<N*N;++i){
        value.push_back(( (3 * v[i][0]) + ( 5 * v[i][1]) - (3 * v[i][3]) - (5 * v[i][2]) ));
    }
    sort(value.begin(),value.end());
    int sum =0;
    for(int i=0;i<K;++i){
        sum += value[i];
    }
    printf("%d",sum);
    return 0;
}

