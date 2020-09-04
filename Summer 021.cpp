#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > vec;
int k;

int FindMax(){

}

int main()
{
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i){
        int c, v; scanf("%d %d", &c, &v);
        vec.push_back({c, v});
    }
    printf("%d", FindMax());
    return 0;
}
