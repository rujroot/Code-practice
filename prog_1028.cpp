/*
    1028 : TOI
    ST : 12.13 23/4/2563 ED : 12.31 23/4/2563
    O(n)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<char,int> m;
    for(int i=0;i<26;++i){
        m.insert({'A'+i,0});
    }
    char Op,var1,var2;
    int num;
    while(true){
        scanf("%c",&Op);
        if(Op == '!'){
            break;
        }
        else if(Op == '='){
            scanf(" %c",&var1);
            scanf("%d",&num);
            m[var1] = num;
        }
        else if(Op == '#'){
            scanf(" %c",&var1);
            printf("%d\n",m[var1]);
        }
        else if(Op == '+'){
            scanf(" %c %c",&var1,&var2);
            m[var1] = m[var1] + m[var2];
        }
        else if(Op == '-'){
            scanf(" %c %c",&var1,&var2);
            m[var1] = m[var1] - m[var2];
        }
        else if(Op == '*'){
            scanf(" %c %c",&var1,&var2);
            m[var1] = m[var1] * m[var2];
        }
        else if(Op == '/'){
            scanf(" %c %c",&var1,&var2);
            m[var1] = m[var1] / m[var2];
        }
    }
    printf("!");
    return 0;
}

//---------<Comment>---------//
//map<char,int>::iterator it;

