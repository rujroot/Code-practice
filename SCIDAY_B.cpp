#include<bits/stdc++.h>
using namespace std;


int main(){
    //printf("%d %d",'A', 'Z');
    char s[10010];
    string Ans;
    int Max = 0;
    scanf("%s", s + 1);
    int l = strlen(s + 1);

    bool Visited[100];
    for(int i = 1; i <= l; ++i){
        for(int j = 65; j <= 90; ++j) Visited[j] = false;

        int C = 0;
        string ss;
        ss.push_back(s[i]);
        Visited[s[i]] = true;
        C++;

        for(int j = i + 1; j <= l; ++j){
            if(Visited[s[j]]){
                if(C > Max){
                    Max = C;
                    Ans = ss;
                }
                break;
            }else{
                Visited[s[j]] = true;
                ss.push_back(s[j]);
                C++;
            }
        }

    }
    cout << Ans;
}