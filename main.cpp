/*  1051 : Logic
    ST : 14.05 2/6/63 ED : 20.00 3/6/63
    O(2^n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<char,char>>> v[3];
vector<pair<char,char>> vinput;
map<char,int> mm;
map<char,int>::iterator itr;
int k,m,n,x,po,last;
char sb,c;
bool Ans;
int Mem(int num,int position){
    if(!Ans)
        return 0;
    if(position > mm.size())
        return 0;
    bool T,fi = true,se = true;
    for(int i=0;i<v[0].size();++i){
        T = false;
        for(int j=0;j<v[0][i].size();++j){
            if(v[0][i][j].first == '-'){
                if(!(num&(1<<mm[v[0][i][j].second]))){
                    T = true;
                    break;
                }
            }else{
                if(num&(1<<mm[v[0][i][j].second])){
                    T = true;
                    break;
                }
            }
        }
        if(!T)
            fi = false;
    }
    for(int i=0;i<v[1].size();++i){
        T = false;
        for(int j=0;j<v[1][i].size();++j){
           if(v[1][i][j].first == '-'){
                if(!(num&(1<<mm[v[1][i][j].second]))){
                    T = true;
                    break;
                }
            }else{
                if(num&(1<<mm[v[1][i][j].second])){
                    T = true;
                    break;
                }
            }
        }
        if(!T)
            se = false;
    }
    if(fi and !se){
        Ans = false;
    }
    Mem(num | 1 << position , position + 1 ),Mem( num , position + 1 );
}
int main()
{
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        scanf("%d %d",&n,&m);
        po = 0;
        last = 0;
        for(int j=0;j<n;++j){
            scanf("%d",&x);
            for(int l=0;l<x;++l){
                scanf(" %c%c",&sb,&c);
                vinput.push_back({sb,c});
                itr = mm.find(c);
                if(itr == mm.end()){
                    mm[c] = po;
                    po++;
                }
            }
            v[0].push_back(vinput);
            vinput.clear();
        }
        for(int j=0;j<m;++j){
            scanf("%d",&x);
            for(int l=0;l<x;++l){
                scanf(" %c%c",&sb,&c);
                vinput.push_back({sb,c});
                itr = mm.find(c);
                if(itr == mm.end()){
                    mm[c] = po;
                    po++;
                }
            }
            v[1].push_back(vinput);
            vinput.clear();
        }
        for(int j=0;j<mm.size();++j){
            last = last|1<<j;
        }
        Ans = true;
        Mem(0,0);
        if(Ans)
            printf("YES\n");
        else
            printf("NO\n");
        v[0].clear();
        v[1].clear();
        mm.clear();
    }
    return 0;
}
