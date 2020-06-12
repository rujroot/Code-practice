/*  1086 : diary
    ST : 14.59 12/6/63 ED : 16.55 12/5/63
    O(n + sum[n]*k)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int n,k,a,sum[110],x,total,day,j;
pair<int,int> Ans = {0,0};
int main()
{

    scanf("%d %d %d",&n,&k,&a);
    sum[0] = 0;
    for(int i=1;i<=n;++i){
        scanf("%d",&x);
        sum[i] = sum[i-1] + x;
    }
    for(int i=1;i<=sum[n];++i){
        total = 0;
        day = 0;
        while(i > sum[day] and day < n){
                day++;
            }
        for(int j=0;j<k;++j){
            if(day > n)
                break;
            while(i+j*a > sum[day] and day < n){
                day++;
            }

            if(i+j*a > sum[day-1] and i+j*a <= sum[day]){
                total++;
                day++;
            }

        }
        if(total > Ans.second){
            Ans.first = i;
            Ans.second = total;
        }
    }
    printf("%d %d",Ans.first,Ans.second);
    return 0;
}

