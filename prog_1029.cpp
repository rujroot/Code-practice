 /* 1029 : Magnet
    ST : 12.35 23/4/63 ED : 22.18 25/4/63
    O(n)
    Rujroot
 */
#include <bits/stdc++.h>
using namespace std;
long long int BinS(vector<long long int> &v,long long int l,long long int r,long long int Find){
    if(r >= l){
        int mid = l+(r-l)/2;
        if(v[mid] > Find and v[mid-1] <= Find)
            return v[mid]-v[mid-1];
        if(v[mid] > Find)
            return BinS(v,l,mid-1,Find);
        return BinS(v,mid+1,r,Find);
    }
    return -1;
}
int main()
{
    set<long long int> s;
    vector<long long int> v;
    long long int Megnet,ST,ED,Find,M,Q;
    scanf("%lld %lld %lld",&Megnet,&M,&Q);

    for(long long int i=0;i<M;++i){
        scanf("%lld %lld",&ST,&ED);
        ED = ST+ED;
        if(!s.count(ST)){
            s.insert(ST);
        }else{
            s.erase(ST);
        }
        if(!s.count(ED)){
            s.insert(ED);
        }else{
            s.erase(ED);
        }
    }
    s.insert(1);
    s.insert(Megnet+1);
    for(auto x:s){
        v.push_back(x);
    }
    for(long long int i=0;i<Q;++i){
        scanf("%lld",&Find);
        printf("%lld\n",BinS(v,0,v.size()-1,Find));
    }

    return 0;
}

