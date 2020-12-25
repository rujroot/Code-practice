#include<bits/stdc++.h>
using namespace std;

int DP[1010][15], p, s, k;
vector<pair<int,int> > v;

int main(){
    scanf("%d %d %d", &p, &s, &k);
    v.push_back(make_pair(0,0));
    for(int i = 0; i < k; ++i){
        int x, y; scanf("%d %d", &x, &y);
        v.push_back(make_pair(x,y));
    }

    for(int i = 1; i <= p; ++i){
        for(int j = 1; j < v.size(); ++j){
            if(j - 1 <= 0 and i - v[j].first < 0)
                DP[i][j] = 0; 
            if(j - 1 <= 0)
                DP[i][j] = DP[i - v[j].first][j] + v[j].second;
            if(i - v[j].first < 0)
                DP[i][j] = DP[i][j - 1];
            else    
                DP[i][j] = max(DP[i][j - 1], DP[i - v[j].first][j] + v[j].second);
        }
    }

    printf("%d", p * s - DP[p][k]);

    return 0;
}