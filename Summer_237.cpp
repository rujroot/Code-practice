#include<bits/stdc++.h>
using namespace std;

stack<int> st;
int Paint[100010];

int main(){
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 1; i <= M; ++i){
        int L, R, C; scanf("%d %d %d", &L, &R, &C);

        if(Paint[L] != 0) Paint[L] = -C;
        else Paint[L] = C;

        if(Paint[R + 1] != 0) Paint[R + 1] *= -1;
        else Paint[R + 1] = -1;
    }

    for(int i = 1; i <= N; ++i){
        printf("%d ", Paint[i]);
    }printf("\n");

    for(int i = 1; i <= N; ++i){
        if(Paint[i] >= 1) st.push(Paint[i]);
        else if(Paint[i] <= -1) st.pop();

        if(st.empty()) printf("0 ");
        else printf("%d ", st.top());
    }

}
