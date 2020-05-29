/*  1076 : lieman
    ST : 19.50 29/5/63 ED : 0.01 30/5/63
    O(2^n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int N,M,Notlie = -2e9,num,l,x;
vector<int> v[30];
int checkAns(vector<int> ch){
    if(ch.size() != 0){
        for(int i=0;i<M;++i){
            num = 0;
            for(int j=0;j<ch.size();++j){
                if(v[i][ch[j]] == 0){
                    continue;
                }
                if(num != 0 and v[i][ch[j]] != num){
                    return 0;
                }
                if(num == 0 and v[i][ch[j]] != 0){
                    num = v[i][ch[j]];
                }

            }
        }
    }
    l = ch.size();
    Notlie = max( Notlie , l );
}
int choose(int i,vector<int> ch,bool get){
    if(i == N){
        checkAns(ch);
        return 0;
    }
    if(get)
        ch.push_back(i);
    choose(i+1,ch,false),choose(i+1,ch,true);
    return 0;
}
int main()
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            scanf("%d",&x);
            v[j].push_back(x);
        }
    }
    vector<int> ch;
    choose(-1,ch,false);
    printf("%d",N-Notlie);
    return 0;
}

