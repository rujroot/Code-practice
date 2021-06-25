#include<bits/stdc++.h>
using namespace std;

vector<char> v[25];
int num[25], R[25], key;
string s;

void right(int po, int l);
void up(int po);
void down(int po);

void Rright(int l);
void Rup();
void Rdown();

void Rup(){
    for(int i = key; i >= 1; --i){
        if(R[i] >= num[i]) return;
        printf("%c", v[i][R[i]]);
        R[i]++;
    }
    Rright(1);
}

void Rright(int l){
    for(int i = 1; i < key - 1; ++i){
        if(R[l] >= num[l]) return;
        printf("%c", v[l][R[l]]);
        R[l]++;
    }
    if(l == 1) Rdown();
    else Rup();
}

void Rdown(){
    for(int i = 1; i <= key; ++i){
        if(R[i] >= num[i]) return;
        printf("%c", v[i][R[i]]);
        R[i]++;
    }
    Rright(key);
}

void down(int po){
    for(int i = 1; i <= key; ++i){
        if(po >= s.size()) return;
        num[i]++;
        po++;
    }
    right(po, key);
}

void right(int po, int l){
    for(int i = 1; i < key - 1; ++i){
        if(po >= s.size()) return;
        num[l]++;
        po++;
    }
    if(l == 1) down(po);
    else up(po);
}

void up(int po){
    for(int i = key; i >= 1; --i){
        if(po >= s.size()) return;
        num[i]++;
        po++;
    }
    right(po, 1);
}

int main(){
    scanf("%d", &key);
    cin >> s;
    up(0);
    int curr = 0;
    for(int i = 1; i <= key; ++i){
        for(int j = 1; j <= num[i]; ++j){
            v[i].push_back(s[curr]);
            curr++;
        }
    }
    Rup();

}
