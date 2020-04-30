/*  1030 : Rice
    ST : 11.40 26/4/63 ED : 17.37 26/4/63
    O(nlogn + n + num) 
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int n,P,Q,num,Buy;
double Tmp;
vector<pair<double,int>> Rice;
double Find(){
    Tmp += Rice.back().first*Rice.back().second;
    Buy -= Rice.back().second;
    Rice.pop_back();
    if(Rice.back().second < Buy){
        return Find();
    }
    return Tmp + Rice.back().first*Buy;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&P,&Q);
        Rice.push_back({(double)P/(double)Q,Q});
    }
    sort(Rice.begin(),Rice.end(),greater<pair<double,int>>());
    scanf("%d",&num);
    for(int i=0;i<num;++i){
        scanf("%d",&Buy);
        if(Rice.back().second > Buy){
            printf("%.3f\n",Rice.back().first*Buy);
            Rice.back().second -= Buy;
        }else if(Rice.back().second == Buy){
            printf("%.3f\n",Rice.back().first*Buy);
            Rice.pop_back();
        }else{
            Tmp = 0;
            printf("%.3f\n",Find());
            Rice.back().second -= Buy;
        }
    }

    return 0;
}

