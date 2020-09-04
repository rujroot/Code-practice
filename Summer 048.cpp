#include <bits/stdc++.h>
using namespace std;
bool a[1000010];
int main()
{
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i){
        scanf("%d", &num);
        a[num] = true;
    }
    for (int i = 1; i <= n; ++i){
        if(!a[i]){
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}
