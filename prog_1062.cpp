/*	1062 : Cromartie Key
    ST : 17.34 16/5/2563 ED : 19.25 16/5/63
    O(n^2 log n)
    Rujroot
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int L,K,St = 0,r = 0,index = 1;
    scanf("%d %d",&L,&K);
    int More = L-K;
    if(More < 0)
        More = 0;
    if(More == 0)
        More = 1;
    r = K-1;
    string M1,M2,Child,Sort;
    cin >> M1;
    cin >> M2;
    cin >> Child;
    for(int i=0;i<(L+K)-1;++i){
        for(int j=St;j>=0;--j){
            Sort.push_back(M1[j]);
            Sort.push_back(M2[j]);
            Sort.push_back(Child[r]);
            sort(Sort.begin(),Sort.end());
            Child[r] = Sort[1];
            Sort.clear();
            r--;
            if(r < 0)
                break;
        }
        if(St < L-1)
            St++;
        if(St == L-1 and More){
            More--;
            r = K-1;
        }else if(St == L-1){
            index++;
            r = K-index;
        }else{
            r = K-1;
        }
    }
    cout << Child;
    return 0;
}
