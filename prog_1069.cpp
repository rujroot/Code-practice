/*  1069 : mazu
    ST : 10.37 23/5/63 ED : 10.44 23/5/63
    o(n)
    Rujroot
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    char x;
    vector<char> v;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf(" %c",&x);
        if(!v.empty() and v.back() == x){
            v.pop_back();
        }else{
            v.push_back(x);
        }
    }
    printf("%d\n",v.size());
    if(v.empty()){
        printf("empty");
        return 0;
    }
    for(int i=v.size()-1;i>=0;--i){
        printf("%c",v[i]);
    }
    return 0;
}

