/*  1050 : Chemical Reactant
    ST : 14.14 7/5/63 ED : 20.46 10/5/63
    O(n^2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int N,P,x;
bool yes;
vector<vector<int>> Ansis,vtmp,v;
vector<int> w,input;
void pAns(){
    vector<int> tob;
    for(int i=0;i<Ansis.size();++i){
        for(int j=0;j<N;++j){
            if(Ansis[i] == vtmp[j]){
                tob.push_back(j+1);
            }
        }
    }
    sort(tob.begin(),tob.end());
    for(int i=0;i<tob.size();++i){
        printf("%d ",tob[i]);
    }
}
bool Less(vector<int> f,vector<int> s){
    for(int i=0;i<P;++i){
        if(f[i] < s[i]) return true;
        else if(f[i] > s[i]) return false;
    }
    return false;
}
int BS(vector<vector<int>> &v,vector<int> &Find,int l,int r){
    if(r >= l){
        int mid = l+(r-l)/2;
        bool LF = Less(Find,v[mid]),LS = Less(v[mid],Find);
        if(LF)
            return BS(v,Find,l,mid-1);
        if(LS)
            return BS(v,Find,mid+1,r);
        if(!LF and !LS)
            return mid;
    }
    return -1;
}
int main()
{
    scanf("%d %d",&N,&P);
    for(int i=0;i<N;++i){
        for(int j=0;j<P;++j){
            scanf("%d",&x);
            input.push_back(x);
        }
        v.push_back(input);
        input.clear();
    }
    vtmp = v;
    for(int i=0;i<P;++i){
        scanf("%d",&x);
        w.push_back(x);
    }
    sort(v.begin(),v.end());
    vector<int> Find;
    for(int i=0;i<N;++i){
        bool self = true;
        for(int j=0;j<P;++j){
            if(w[j] - v[i][j] != 0)
                self = false;
        }
        if(self){
            Ansis.push_back(v[i]);
            pAns();
            return 0;
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<P;++j){
            Find.push_back(w[j] - v[i][j]);
        }
        int Ans = BS(v,Find,0,N-1);
        if(Ans != -1 and Ans != i){
            Ansis.push_back(v[i]);
            Ansis.push_back(v[Ans]);
            pAns();
            return 0;
        }
        Find.clear();
    }
    printf("NO");
    return 0;
}

