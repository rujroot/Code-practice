#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r,n,num;
    scanf("%d %d ",&r,&n);
    vector<pair<int,int> > O(r+5,{r,r});
    string path[r+5];
    for(int i=0;i<r;++i){
        cin >> path[i];
        for(int j=0;j<n;++j){
            if(path[i][j] == 79){
                if(O[j].first == r){
                    O[j] = {i,j};
                    //printf("%d %d\n",O[j].first,O[j].second);
                }
            }
        }
    }
   /* for(int i=0;i<n;++i){
        printf("%d %d\n",O[i].first,O[i].second);
    }*/
    for(int i=0;i<n;++i){
        scanf("%d",&num);
        for(int j=0;j<r;++j){
            if(O[i].first-j > 0 && O[i].first-j <= num)
                path[j][i] = '#';
        }
    }
    for(int i=0;i<r;++i){
        cout << path[i] << "\n";
    }
    return 0;
}
