/*  1035 : Prime Palindrome
    ST : 15.02 28/4/63 ED : 15.48 28/4/63
    o(n*sqrt(n))
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> Num;
void makeNum(int num){
    if(num < 10){
        Num.push_back(num % 10);
    }else{
        Num.push_back(num % 10);
        makeNum(num/10);
    }

}
bool f(int n){
    if(n < 2)  return 0;
    int i = 2;
    while(i*i <= n){
        if(n%i==0)
            return 0;
        i = i + 1;
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=n;i<=2400000;++i){
        if(f(i)){
            bool have = true;
            Num.clear();
            makeNum(i);
            for(int i=0;i<Num.size()/2;++i){
                if(Num[i] != Num[Num.size()-1-i]){
                    have = false;
                }
            }
            if(have){
                printf("%d",i);
                break;
            }
        }
    }
    return 0;
}

