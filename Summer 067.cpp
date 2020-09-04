/*
    Summer 067
    29/8/63
    ST : 21.20
    ED : 21.24

*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1;
    cin >> s1;
    map<char, int> m;
    for (int i = 0; i < s1.size(); ++i){
        m[s1[i]]++;
    }

    string s2;
    cin >> s2;
    for (int i = 0; i < s2.size(); ++i){
        if(m[s2[i]] == 0){
            printf("No");
            return 0;
        }
        m[s2[i]]--;
    }
    printf("Yes");
    return 0;
}
