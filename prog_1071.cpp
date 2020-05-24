/*  1071 : bomb
    ST : 19.20 24/5/63 ED : 23.22 24/5/63
    O(n^2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> v[1010];
bool visited[1010][1010];
int x,y,z,N,M,l,num;

int main()
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;++i){
        scanf("%d %d",&x,&y);
        v[y].push_back(x);
    }
    for(int i=0;i<M;++i){
        scanf("%d %d %d",&x,&y,&z);
        num = 0;
        l = y-z;
        if(y-z <= 0){
            l = 0;
        }
        for(int j=l;j<=y+z;++j){
            if(v[j].size() != 0){
                for(int k=0;k<v[j].size();++k){
                    if(!visited[j][k] and v[j][k] >= x-z and v[j][k] <= x+z){
                        num++;
                        visited[j][k] = true;
                    }
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}

