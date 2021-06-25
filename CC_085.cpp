#include<bits/stdc++.h>
using namespace std;

int C[30], Min = 2e9;

int main(){
    string s;
    cin >> s;
    for(int i = 1; i <= s.size() / 2; ++i){
        if(s.size() % i == 0){
            int sum = 0;
            for(int j = 0; j < i; ++j){
                int Max = 0;
                for(int j = 0; j <= 30; ++j) C[j] = 0;
                for(int k = j; k < s.size(); k += i){
                    C[s[k] - 'a']++;
                    Max = max(Max, C[s[k] - 'a']);
                }
                sum += (s.size() / i) - Max;
            }
            Min = min(sum, Min);
        }
    }
    printf("%d", Min);
}
