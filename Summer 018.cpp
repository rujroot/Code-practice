
#include <bits/stdc++.h>

using namespace std;
char ans[110][110], s[2000];
int main()
{
    int n, m, po = 0;
    gets(s);
    scanf("%d %d",&n, &m);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ans[i][j] = '.';
        }
    }

    for(int i = m - 1; i >= 0; --i){
        for(int j = 0;j < n; ++j){
            ans[j][i] = s[po];
            po++;
            if(po >= strlen(s))
                break;
        }
        if(po >= strlen(s))
                break;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(ans[i][j] == ' ')
                printf(".");
            else
                 printf("%c",ans[i][j]);
        }
    }
    return 0;
}
