/*  1043 : Power
    ST : 11.15 1/5/2563 ED : 11.51 1/5/2563
    O(n*sqrt(number)*log(j)) ~~ O(n^1.5 * log(j)) ???
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,Max,ch,loop;
    long long int number,tmp;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        Max = -1;
        scanf("%lld",&number);
        tmp = number;
        loop = sqrt(number);
        for(int j=2;j<=loop;++j){
            number = tmp;
            if(number % j == 0){
                ch = 0;
                while(number % j == 0){
                    number /= j;
                    ch++;
                }

                if(number == 1){
                    Max = max(ch,Max);
                }
            }
        }
        if(Max != -1){
            printf("%d\n",Max);
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

