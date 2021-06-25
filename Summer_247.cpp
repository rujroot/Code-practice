#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;

int main(){
    int n; scanf("%d", &n);
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    set<int> s;
    set<int>::iterator it;
    for(int i = 0; i < n; ++i){
        int m; scanf("%d", &m);
        if(m == 1){
            int x; scanf("%d", &x);
            s.insert(x);
            it = s.find(x);
            int F = *prev(it), B = *next(it);
            if(it != s.begin()) pq.emplace(abs(x - F), x, F);
            if(it != s.end()) pq.emplace(abs(x - B), x, B);
        }else if(m == 2){
            int x; scanf("%d", &x);
            it = s.find(x);
            if(it != s.begin() and it != s.end()){
                int F = *prev(it), B = *next(it);
                pq.emplace(abs(F - B), F, B);
            }
            s.erase(s.find(x));
        }else if(m == 3){
            while(!pq.empty() and (!s.count(get<1>(pq.top())) or !s.count(get<2>(pq.top())))) pq.pop();
            printf("%d\n", get<0>(pq.top()));
        }else{
            printf("%d\n", *prev(s.end()) - *s.begin());
        }
    }

}
