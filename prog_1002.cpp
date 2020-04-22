#include <bits/stdc++.h>
using namespace std;
int Ans[10];
int main()
{
    int d,N[5];
    scanf("%d",&d);
    for(int i=1;i<=d;++i){
        N[0] = i/100;
        N[1] = (i%100)/10;
        N[2] = (i%100)%10;
        if(N[0] > 0){
            if(N[0] == 4){
                Ans[4]++;
            }else{
                Ans[4] += N[0];
            }
        }
        if(N[1] > 0){
            if(N[1] == 9){
                Ans[4]++;
                Ans[2]++;
            }else if(N[1] > 4){
                Ans[3]++;
                Ans[2] += (N[1]-5);
            }else if(N[1] == 4){
                Ans[3]++;
                Ans[2]++;
            }else{
                Ans[2] += N[1];
            }
        }
        if(N[2] > 0){
            if(N[2] == 9){
                Ans[2]++;
                Ans[0]++;
            }else if(N[2] > 4){
                Ans[1]++;
                Ans[0] += N[2]-5;
            }else if(N[2] == 4){
                Ans[1]++;
                Ans[0]++;
            }else{
                Ans[0] += N[2];
            }
        }
        //printf("%d\n",i);
         //printf("%d %d %d %d %d\n",Ans[0],Ans[1],Ans[2],Ans[3],Ans[4]);
    }
    for(int i=0;i<5;++i){
        printf("%d ",Ans[i]);
    }
    return 0;
}
