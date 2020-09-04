/*
    ST : 20.50
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int num; scanf("%d", &num);
        v.push_back(num);
    }
    for (int i = n-1; i >= 0; --i){
        printf("%d ",v[i]);
    }
    return 0;
}
