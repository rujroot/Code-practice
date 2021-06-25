#include<bits/stdc++.h>
#define n 200010
using namespace std;
vector<int> org;
bool visited[n];
int color[n], num[n];

void coloring(int u, int c, int x, vector<int> &v){
    if(visited[u]) return;
    visited[u] = true;
    color[u] = c;
    num[u] = x;
    coloring(v[u], c, x + 1, v);
}

bool isSame(int a, int b){
    return color[a] == color[b];
}

bool solve(int s, int e, int a, int b){
    if(isSame(s, e)){
        if(isSame(s, a) and !isSame(a, b)) return true;
        if(isSame(s, b) and !isSame(a, b)) return true;
        if(!isSame(a, b) and !isSame(a, s) and !isSame(b, s)) return true;
        if(isSame(a, b) and !isSame(a, s)) return true;

        if(num[s] > num[e]) swap(s, e);
        return ((num[s] > num[a] and num[s] <= num[b]) == (num[e] > num[a] and num[e] <= num[b]));
    }else{
        if(isSame(s, a) and isSame(e, b)) return true;
        if(isSame(s, b) and isSame(e, a)) return true;
        else return false;
    }
}

int main(){
    int N, Q; scanf("%d %d", &N, &Q);
    org.push_back(0);
    for(int i = 1; i <= N; ++i){
        int x; scanf("%d", &x);
        org.push_back(x);
    }
    int c = 1;
    for(int i = 1; i <= N; ++i){
        if(!visited[i]){
            coloring(i, c, 1, org);
            c++;
        }
    }
    for(int i = 0; i < Q; ++i){
        int s, e, a, b;
        scanf("%d %d %d %d", &s, &e, &a, &b);
        if(solve(s, e, a ,b)) printf("DEAD\n");
        else printf("SURVIVE\n");

    }
}
