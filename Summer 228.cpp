#include <bits/stdc++.h>

using namespace std;

char Ans[1010][10];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for (int j = 0; j < 4; ++j){
            Ans[i][j] = s[j];
        }
    }
    bool d = false, f = false, j = false, k = false;
    for (int i = n - 1; i >= 0; --i){
            printf("at t=%d\n",n - i - 1);
           if(!d and Ans[i][0] == '#'){
                d = true;
                printf("down d\n");
           }else if(d and Ans[i][0] == '-'){
                d = false;
                printf("up d\n");
           }

           if(!f and Ans[i][1] == '#'){
                f = true;
                printf("down f\n");
           }else if(f and Ans[i][1] == '-'){
                f = false;
                printf("up f\n");
           }

           if(!j and Ans[i][2] == '#'){
                j = true;
                printf("down j\n");
           }else if(j and Ans[i][2] == '-'){
                j = false;
                printf("up j\n");
           }

           if(!k and Ans[i][3] == '#'){
                k = true;
                printf("down k\n");
           }else if(k and Ans[i][3] == '-'){
                k = false;
                printf("up k\n");
           }
    }
    printf("at t=%d\n",n);
    if(d){
        printf("up d\n");
    }
    if(f){
        printf("up f\n");
    }
    if(j){
        printf("up j\n");
    }
    if(k){
        printf("up k\n");
    }
    /*for (int i = 0; i < n; ++i){
        for(int j = 0; j < 4; ++j){
            printf("%c",Ans[i][j]);
        }printf("\n");
    }*/
    return 0;
}
