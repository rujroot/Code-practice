#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num,x,sum,Max=-2e9,ansi,st,ed;
    scanf("%d",&num);
    vector<int> Number;
    for(int i=0;i<num;++i){
        scanf("%d",&x);
        Number.push_back(x);
    }
    for(int i=0;i<Number.size();++i){
        sum = Number[i];
        if(sum > Max and sum > 0){
            Max = sum;
            st = i;
            ed = i;
        }
        for(int j=i+1;j<Number.size();++j){
            if(Number[i] < 0){
                break;
            }
            if(sum + Number[j] > 0 and sum + Number[j] > Max){
                sum += Number[j];
                Max = sum;
                ed = j;
                st = i;
            }else if(sum + Number[j] > 0){
                sum += Number[j];
            }
            else{
                break;
            }
        }
    }
        if(Max == -2e9){
            printf("Empty sequence");
            return 0;
        }
        for(int i=st;i<=ed;++i){
            printf("%d ",Number[i]);
        }
        printf("\n%d",Max);
        return 0;
}
