#include <bits/stdc++.h>

using namespace std;
bool prime[2000];
int main()
{
    int n;
    scanf("%d",&n);
    prime[1] = true;
    for(int i = 2; i <= 1000; ++i){
        if(!prime[i]){
            for(int j = i + i; j <= 1000; j += i){
                prime[j] = true;
            }
        }
    }
    for(int i = 2;i <= 1000; ++i){
        if(!prime[i] and n % i == 0){
            printf("%d %d",i ,n/i);
            return 0;
        }
    }
    return 0;
}
