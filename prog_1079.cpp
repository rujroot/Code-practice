/*  1079 : pot
    ST : 11.52 4/6/63 ED 11.25 7/6/63
    O(n)
    Rujroot
*/
#include<bits/stdc++.h>
int N,K,mem[100010],sum[100010];
int main()
{
	scanf("%d %d",&N,&K);
	mem[0] = 1;
	sum[0] = 1;
	for(int i=1;i<=N;++i){
        if(i-K-1 < 0)
            mem[i] = sum[i-1]%2009;
        else{
            if(sum[i-1] <= sum[i-K-1]){
                sum[i-1] += 2009;
            }
            mem[i] = (sum[i-1] - sum[i-K-1])%2009;
        }
        sum[i] += (sum[i-1] + mem[i])%2009;
        sum[i-1] %= 2009;
	}
    printf("%d",mem[N]);
}

