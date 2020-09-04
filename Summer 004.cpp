#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,m;
    string s;
    //printf("%d %d",'A','Z');
    scanf("%d %d",&n,&k);
    k %= 26;
    cin >> s;
    for(int i=0;i<n;++i){
        if((s[i] + k > 122 and s[i] >= 97 and s[i] <=122) or (s[i] + k > 90 and s[i] >= 65 and s[i] <= 90)){
            s[i] += k - 26;
        }
        else if((s[i] + k < 97 and s[i] >= 97 and s[i] <=122) or (s[i] + k < 65 and s[i] >= 65 and s[i] <= 90)){
            s[i] += k + 26;
        }
        else{
            s[i] += k;
        }
    }
    cout << s;
    return 0;
}
