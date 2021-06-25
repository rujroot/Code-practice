#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[10][100010], rp[10][100010];
    for(int i = 0; i < 5; ++i){
        scanf("%s", &s[i]);
        char *p;
        int len = 0, Maxlen = strlen(s[i]);
        while(true){
            rp[i][len] = s[i][len];
            s[i][len] = '*';
            len++;
            p = strstr(s[i], rp[i]);

            int po = p - s[i];
            if(po == len){
                int ans = 0, tmp = len;
                printf("%d %d\n", Maxlen, len);
                while(Maxlen >= len){
                    if(Maxlen % len == 0) ans++;
                    len += tmp;
                }
                printf("%d\n", ans);
                break;
            }
            if(len == Maxlen){
                printf("1\n");
                break;
            }
        }

    }
}
