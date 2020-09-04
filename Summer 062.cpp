#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, int> > v[1000];
    v[0].push_back({1,1});
    for(int i = 0; i < 20; ++i){
        for(int j = 0; j < v[i].size(); ++j){
            v[i + 1].push_back({v[i][j].first + v[i][j].second, v[i][j].second});
            v[i + 1].push_back({v[i][j].first, v[i][j].first + v[i][j].second});
        }
    }
    for(int i = 0;i < 20; ++i){
        printf("i == %d\n", i);
        for(int j = 0; j < v[i].size(); ++j){
            if(v[i][j].first == 17){
                printf("{%d,%d} ",v[i][j].first, v[i][j].second);
            }
        }printf("\n");
    }
    return 0;
}
