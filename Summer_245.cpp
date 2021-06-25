#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppii;

string s;
bool visited[100010];
int Ans[1010][1010];

ppii get(pii po1, pii po2, int D){
    int ti = po1.first, tj = po1.second, di = po2.first, dj = po2.second;
    if(D == 0) return { {ti, tj} , {(ti + di) / 2, (tj + dj) / 2}};
    else if(D == 1) return {};
    else if(D == 2) return {};
    else return {};
}

void Di(pii po1, pii po2, int pos){
    int D = 0;
    for(int i = pos; i < s.size(); ++i){
        if(visited[i]) continue;
        visited[i] = true;
        if(s[i] == 'D'){
            Di( get(po1, po2, D).first, get(po1, po2, D).second , pos + 1);
            D++;
        }else{

        }
    }

}

int main(){
    int n , m ; scanf("%d %d", &n, &m);
    cin >> s;
    Di({1, 1}, {n, m}, 0);
}
