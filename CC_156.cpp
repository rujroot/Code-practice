#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    string cc = "codecube";
    int Add = 0, po = 0;
    for(int i = 0; i < s.size(); ++i){
        while(s[i] != cc[po]){
            //printf("%d\n", i);
            Add++;
            po++;
            if(po >= cc.size()) po = 0;
        }
        po++;
        if(po >= cc.size()) po = 0;
    }
    if(po != 0) Add += 8 - po;
    printf("%d", Add);
}
