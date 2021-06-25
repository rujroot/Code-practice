#include<bits/stdc++.h>
using namespace std;

list<char> l;

int main(){
    string s; cin >> s;
    auto it = l.end();
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '[') it = l.begin();
        else if(s[i] == ']') it = l.end();
        else l.insert(it, s[i]);
    }
    while(!l.empty()){
        printf("%c", l.front());
        l.pop_front();
    }
}
