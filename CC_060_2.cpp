#include<bits/stdc++.h>
using namespace std;
#define N 100010

int L[N], R[N], ql[N], qr[N], s, t, Max, sum, Long = 2e9;
char ac;

int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        char c; int x; scanf(" %c ", &c); scanf("%d", &x);
        if(c == 'L'){
            L[i] = -x;
            R[i] = x;
            ql[i] = ql[i - 1] + x;
            qr[i] = qr[i - 1];
        }else{
            L[i] = x;
            R[i] = -x;
            ql[i] = ql[i - 1];
            qr[i] = qr[i - 1] + x;
        }
    }

    Max = 0, sum = 0;
    vector<int> v;
    for(int i = 1; i <= n; ++i){
        if(sum + R[i] > 0){
            v.push_back(i);
            sum += R[i];
        }else{
            sum = 0;
            v.clear();
        }
        int suma = 0;
        if(!v.empty()) suma = (qr[n] - qr[v[v.size() - 1]] + qr[v[0] - 1]) + ql[v[v.size() - 1]] - ql[v[0] - 1];
        //if(!v.empty())printf("%d %d\n", v[0], v[v.size() - 1]);
        if(suma > Max){
            ac = 'R';
            s = v[0];
            t = v[v.size() - 1];
            Long = v.size();
            Max = suma;
        }else if(suma == Max and Long > v.size() and !v.empty()){
            ac = 'R';
            s = v[0];
            t = v[v.size() - 1];
            Long = v.size();
            Max = suma;
        }
    }

    sum = 0;
    for(int i = 1; i <= n; ++i){
        if(sum + L[i] > 0){
            v.push_back(i);
            sum += L[i];
        }else{
            sum = 0;
            v.clear();
        }
        int suma = 0;
        if(!v.empty()) suma = (ql[n] - ql[v[v.size() - 1]] + ql[v[0] - 1]) + qr[v[v.size() - 1]] - qr[v[0] - 1];
        if(suma > Max){
            ac = 'L';
            s = v[0];
            t = v[v.size() - 1];
            Long = v.size();
            Max = suma;
        }else if(suma == Max and Long > v.size() and !v.empty()){
            ac = 'L';
            s = v[0];
            t = v[v.size() - 1];
            Long = v.size();
            Max = suma;
        }
    }
    printf("%c %d %d %d",ac , Max, s, t);

}
