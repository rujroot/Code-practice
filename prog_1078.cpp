/*  1078 : atom_max
    ST : 12.21 4/6/63 ED : 21.17 5/6/63
    O(n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int N,x,med,sum = 0;
    vector<long long int> v;
    stack<long long int> st;
    scanf("%lld",&N);
    int Use = N/2;
    for(int i=0;i<N;++i){
        scanf("%lld",&x);
        v.push_back(x);
    }
    nth_element(v.begin(),v.begin()+v.size() / 2,v.end());
    med = v[v.size()/2];
    for(int i=0;i<N;++i){
        if(v[i] <= med and Use){
            Use--;
            st.push(-v[i]);
        }else{
            sum += (v[i] + st.top());
            st.pop();
        }
    }
    printf("%lld",sum);
    return 0;
}

