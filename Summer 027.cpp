#include <bits/stdc++.h>
using namespace std;
int main()
{
    int Q,n,L,Climb,Ans;
    scanf("%d",&Q);
    for(int i=0;i<Q;++i){
        scanf("%d %d",&n,&L);
        if(n == L){
            printf("%d\n",n);
            continue;
        }
        if(n % 2 == 0){
            Climb = n/2;
            if(Climb % L == 0)
                printf("%d\n",Climb);
            else{
                Ans = Climb / L + 1;
                if(Climb * 2 >= Ans*L)
                    printf("%d\n",Ans*L);
                else
                    printf("-1\n");
            }
        }else{
            Climb = n / 2 + 1;
            if(Climb % L == 0)
                printf("%d\n",Climb);
            else{
                Ans = Climb / L + 1;
                if((Climb-1) * 2 >= Ans*L)
                    printf("%d\n",Ans*L);
                else
                    printf("-1\n");
            }

        }
    }
    return 0;
}
