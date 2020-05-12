/*  1055 : Wheel
    ST 23.12 11/5/63 ED : 17.55 12/5/63
    O(n^2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int N,K,x;
vector<int> v,dice;
bool visited[110];
int value[25];
int main()
{

    scanf("%d %d",&N,&K);
    for(int i=0;i<N;++i){
        scanf("%d",&x);
        v.push_back(x);
    }
    for(int i=0;i<N;++i){
        scanf("%d",&x);
        dice.push_back(x);
    }
    int po = 0,curr = 0;
    for(int i=0;i<dice.size();++i){
        int Move = 0;
        while(Move < dice[i]){
            if(!visited[curr]){
                curr++;
                Move++;
            }else{
                curr++;
            }
            if(curr >= N){
                curr = 0;
            }
        }
        if(visited[curr]){
            while(visited[curr]){
                curr++;
                if(curr >= N){
                    curr = 0;
                }
            }
        }
        value[po] += v[curr];
        visited[curr] = true;
        po++;
        if(po >= K){
            po = 0;
        }
    }
    for(int i=0;i<K;++i){
        printf("%d\n",value[i]);
    }
    return 0;
}

