/*  0021 : Kemija
    ST : 23.25 8/5/2563 ED : 23.37 8/5/2563
    O(n)
    Rujroot
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[110];
    string ans;
    scanf("%[^\n]",s);
    int l = strlen(s);
    for(int i=0;i<l;++i){
        ans.push_back(s[i]);
        if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u'){
            i+=2;
        }
    }
    cout << ans;
    return 0;
}

