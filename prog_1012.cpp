#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d,e,num,sum=0;
    scanf("%d",&num);
    for(int i=0;i<num;++i){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        sum += (a*8+b*6+c*4+d*2+e);
    }
    if(sum % 8 == 0){
        printf("%d",sum/8);
    }else{
        printf("%d",(sum/8)+1);
    }
    return 0;
}
