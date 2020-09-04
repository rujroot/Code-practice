#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, id = 0, x;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", &x);
        v.push_back(x);
        if(v[i] == v[i - 1]){
            printf("No");
            return 0;
        }
    }
    bool dc = false, inc = true;
    if(v[0] > v[1]){
        dc = true;
        inc = false;
    }
    for (int i = 1; i < n-1; ++i){
        if(inc and v[i] > v[i + 1]){
            inc = false;
            id++;
        }
        else if(!inc and v[i] < v[i + 1]){
            if(dc){
                printf("No");
                return 0;
            }
            inc = true;
            id++;
        }
    }
    //printf("id == %d",id);
    if(id < 2)
        printf("Yes");
    else
        printf("No");
    return 0;
}
