/*
	O(n log n)
*/
#include <bits/stdc++.h>
using namespace std;
int po,val,bsval,mem[300010],N,x;
vector<pair<int,int>> Sort,Ans;
long long int sum[300010];
int bs(int l,int r,int x){
    if(r >= l){
        int mid = l + (r - l) / 2;
        int Tsum1 = sum[mid],Tsum2 = sum[mid-1];
        if(po <= mid){
            Tsum1 -= val;
        }
        if(po <= mid-1){
            Tsum2 -= val;
        }
        if(Tsum1 == x)
            return mid;
        if(Tsum2 < x and Tsum1 > x){
            return mid;
        }
        if(Tsum1 > x)
            return bs(l , mid - 1,x);
        return bs(mid + 1,r,x);
    }
    return -1;
}
int main()
{

    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&x);
        Sort.push_back({x,i});
    }
    sort(Sort.begin(),Sort.end(),greater<pair<int,int>>());
    for(int i=0;i<N;++i){
        sum[i+1] = sum[i] + Sort[i].first;
    }
    for(int i=1;i<=N;++i){
        if(mem[Sort[i-1].first] != 0){
            Ans.push_back({Sort[i-1].second, mem[Sort[i-1].first]});
            continue;
        }
        po = i;
        val = Sort[i-1].first;
        bsval = bs(1,N,(sum[N]/2 + 1) - Sort[i-1].first);
        if(bsval > po)
            bsval--;
        mem[Sort[i-1].first] = bsval;
        Ans.push_back({Sort[i-1].second, bsval});
    }
    sort(Ans.begin(),Ans.end());
    for(int i=0;i<N;++i){
        printf("%d\n",Ans[i].second);
    }
    return 0;
}
