#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, num;
    vector<int> v;
    vector<pair<int, int> > Sort;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%d", &num);
        v.push_back(num);
        Sort.push_back({num, i});
    }
    sort(Sort.begin(), Sort.end());
    for (int i = 0; i < m; ++i){
        scanf("%d", &num);
        if(num - 1 != Sort[0].second)
            printf("%d\n", Sort[0].first);
        else
             printf("%d\n", Sort[1].first);
    }
    return 0;
}
