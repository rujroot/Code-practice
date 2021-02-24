#include<bits/stdc++.h>
using namespace std;

char s[1000010];
long long Q[1000010];
map<long long, int> m;
int Ans;

int main(){
    int k, n;
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; ++i){
        if(s[i] == 'R')
            Q[i] += Q[i - 1] - k;
        else
            Q[i] += Q[i - 1] + 1;

        if(!m[Q[i]])
            m[Q[i]] = i;
        else
            Ans = max(Ans, i - m[Q[i]]);
            
    }
    printf("%d", Ans);
}