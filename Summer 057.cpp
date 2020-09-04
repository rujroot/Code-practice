#include <bits/stdc++.h>
using namespace std;

int n, Next[110], walk[101];

int Move(int i, int j){
    int num = 0, po;
    for (int p = 1; p <= n; ++p){
        if(Next[p] == i)
            po = p ;
    }
    while(Next[po] != j){
        num++;
        po++;
        if(po > n){
            po = 1;
        }
    }
    return num;
}
int main()
{
    int m, b[1010];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i){
        if(i == n)
            scanf("%d", &Next[1]);
        else
            scanf("%d", &Next[i+1]);
    }
    for (int i = 1; i <= m+1; ++i){
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= m; ++i){
        walk[b[i + 1]] += Move(b[i + 1] , b[i]);
    }
    for (int i = 1; i <= n; ++i){
        printf("%d ", walk[i]);
    }
    return 0;
}
