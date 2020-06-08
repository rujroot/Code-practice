/*  1080 : triagain
    ST : 11.40 7/6/63 ED : 13.35 7/6/63
	O(n log n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,x,Max = 0,sum;
    vector<int> v;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(v.size() < 3){
        printf("%d",v.size());
        return 0;
    }
    for(int i=0;i<v.size()-1;++i){
        sum = 0;
        for(int j=i+2;j<v.size();++j){
            if(v[i] + v[i+1] <= v[j]){
                break;
            }
            sum++;
        }
        Max = max(Max,sum + 2);
    }
    printf("%d",Max);
    return 0;
}
