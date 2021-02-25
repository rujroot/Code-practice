   
#include <bits/stdc++.h>
using namespace std;

string s = "1";

string lookAndSay(int N) {
    N--;
    while(N--){
        char C = s[0]; 
        int Q = 1;
        string Copy;
        s.push_back('-');
        for(int i = 1; i < s.size(); ++i){
            if(C != s[i]){
                Copy.push_back(Q + '0');
                Copy.push_back(C);
                C = s[i];
                Q = 1;
                
            }else{
                Q++;
            }
            
        }
        s = Copy;
    }
    return s;
}
   
int main() {
    int N;
    cin >> N;
    cout << lookAndSay(N);
}
