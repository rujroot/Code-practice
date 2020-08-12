#include <bits/stdc++.h>
using namespace std;
bool prime[1000001];
int main()
{
    long long int N,num,sqr;
    prime[0] = prime[1] = 1;
    for(int i = 2;i<=1000000;++i){
        if(prime[i] == 0){
            for(int j = i + i;j<=1000000;j+=i){
                prime[j] = 1;
            }
        }
    }
    scanf("%lld",&N);
    for(int i=0;i<N;++i){
        scanf("%lld",&num);
        sqr = sqrt(num);
        if(sqr * sqr == num and !prime[sqr])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
