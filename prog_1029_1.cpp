/*
    1029 : Magnet
    ST : 12.35 23/4/2563 ED : ???
    O(n^2)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int num;
    long long int Swap,Ask,a,k,position,Up,Down;
    scanf("%lld",&num);
    vector<long long int> Magnet(num,1);
    scanf("%lld %lld",&Swap,&Ask);
    for(long long int i=0;i<Swap;++i){
        scanf("%lld %lld",&a,&k);
        for(long long int j=a-1;j<a+k-1;++j){
            Magnet[j] = -Magnet[j];
        }
    }
    for(int i=0;i<Ask;++i){
        scanf("%lld",&position);
        position -= 1;
        Up = position; Down = position;
        for(long long int j=Up;j>=0;--j){
            if(j-1 < 0 or Magnet[position] != Magnet[j-1]){
                Up = j;
                break;
            }
        }
        for(long long int j=Down;j<num;++j){
            if(j+1 >= num or Magnet[position] != Magnet[j+1]){
                Down = j;
                break;
            }
        }
        printf("%lld\n",Down-Up+1);
    }
    /*for(int i=0;i<Magnet.size();++i){
        printf("%d %d\n",Magnet[i].first,Magnet[i].second);
    }*/
    return 0;
}

