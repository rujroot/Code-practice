#include <bits/stdc++.h>
using namespace std;

map<string, pair<string, int> >m;

int main()
{
    int n;
    string s1, s2, s3;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        cin >> s1;
        cin >> s2;
        if(m[s1].first == ""){
            m[s1].first = s1;
        }
        s3 = m[s1].first;
        while(m[s3].first != m[s1].first){
            m[s1].first = m[s3].first;
            s3 = m[s3].first;
        }
    }
    return 0;
}
