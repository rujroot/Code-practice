#include <bits/stdc++.h>

using namespace std;
int sky[30010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int l, r, h; scanf("%d %d %d", &l, &r, &h);
        for(int j = l; j < r; ++j){
            if(h > sky[j])
                sky[j] = h;
        }
    }
    for (int i = 0; i < 30000; ++i){
       if(sky[i] != sky[i + 1])
        printf("%d %d\n", i + 1, sky[i + 1]);
    }
    return 0;
}
