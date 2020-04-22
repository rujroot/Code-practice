/*  1025 : LCM
    ST: 11.10 22/4/2563 ED: 14.59 22/4/2563
    O(n log n)
    Rujroot                                 */

#include <bits/stdc++.h>
using namespace std;
long long int number[50010],ans;
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&number[i]);
    }
    ans = number[0]*number[1]/__gcd(number[0],number[1]);
    for(int i=2;i<n;++i){
        ans = ans*number[i]/__gcd(ans,number[i]);
    }
    printf("%lld",ans);
     return 0;
}




//---------<Comment>------//
//int End = number[i];
    /*for(int i=0;i<n;++i){
        bool Have = false;
        int num;

        //if(Have){
            //j=1;
            //Ans *= num;
        //}
    }*/
    /*printf("%d",Ans);
    for(int i=0;i<n;++i){
        for(int j=0;j<Fac[i].size();++j){
                printf("%d ",Fac[i][j]);
            }
            printf("\n");
    }*/
//Max = max(Max,number[i]);
/*long long int LCM(long long int n1,long long int n2){
    long long int Max= max(n1,n2);
    //printf("n1 = %d n2 = %d",n1,n2);
    long long int gcd = 1;
    for(long long int j=Max;j>2;--j){
        if(n1 % j == 0 and n2 % j == 0){
            gcd = j;
            break;
        }
            /*if(number[i] % j == 0){
                Fac[i].push_back(j);
                number[i] = number[i]/j;
                if(number[i] == 1){
                    break;
                }
                j=1;
                //Have = true;
            }
    }
    //printf("GCD = %d n1*n2 = %d\n",gcd,n1*n2);
    return (n1*n2)/gcd;
}*/

