/* 1024 : Factory
DATE: 21/4/63 ST: 14.54  ED : 15.34*/
//printf("n1 = %d n2 = %d Dif = %d Max = %d Min = %d\n",n1,n2,Dif,Max,Min);
//printf("%d %d %d\n",i,j,n-i-j);
//printf("%d",Ave);
#include <bits/stdc++.h>
using namespace std;
vector<int> Factory;
int x,n,Dif = 2e9,Money[5],Ans[5];
void calculate(int n1,int n2,int n3){
    Money[0] = 0;
    Money[1] = 0;
    Money[2] = 0;
    for(int i=1;i<=n1;++i){
        Money[0] += Factory[i];
    }
    for(int j=n1+1;j<=n1+n2;++j){
        Money[1] += Factory[j];
    }
    for(int k=n1+n2+1;k<=n1+n2+n3;++k){
        Money[2] += Factory[k];
    }
    int Max = max(Money[0],max(Money[1],Money[2]));
    int Min = min(Money[0],min(Money[1],Money[2]));
    if(Max-Min < Dif){
        Dif = Max-Min;
        Ans[0] = n1;
        Ans[1] = n1+1;
        Ans[2] = n1+n2+1;
    }
}

int main()
{
    Factory.push_back(0);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        Factory.push_back(x);
    }
    for(int i=1;i<=n-2;++i){
        for(int j=1;j<=n-i-1;++j){

            calculate(i,j,n-i-j);
        }
    }
    printf("%d %d",Ans[1],Ans[2]);
    return 0;
}

