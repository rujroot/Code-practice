#include<bits/stdc++.h>
using namespace std;

int num[510];
char o[510];

long long Min[510], Max[510];

long long Convert(int num, int i){
    if(o[i] == '-') return -num;
    return num;
}

int main(){
    int n; scanf("%d", &n);
    o[1] = '+';
    for(int i = 1; i <= n; ++i){
        scanf("%d", &num[i]);
        if(i != n)
            cin >> o[i + 1];
        Max[i] = -9e18;
        Min[i] = 9e18;
    }


    for(int i = n; i >= 1; --i){
        Min[i] = min(Min[i], Convert(num[i], i) + Min[i + 1]);
        long long Mini = num[i];
        for(int j = i + 1; j <= n; ++j){
            Mini += Convert(num[j], j);
            Min[i] = min(Min[i], Convert(Mini, i) + Min[j + 1]);
        }
    }
    for(int i = n; i >= 1; --i){
        Max[i] = max(Max[i], Convert(num[i], i) + Max[i + 1]);
        long long Maxi = num[i];
        for(int j = i + 1; j <= n; ++j){
            Maxi += Convert(num[j], j);
            Max[i] = max(Max[i], Convert(Maxi, i) + Max[j + 1]);
        }

    }

    printf("%lld %lld", Min[1], Max[1]);
}
