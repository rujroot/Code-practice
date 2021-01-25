//ST : 22.12 25/1/64
#include<bits/stdc++.h>
using namespace std;

double Ans = 9e18, A1[20], A2[20];
int n;

double Solve(int i, int Ch){
    if(i > n)
        return 9e18;
    if(i == n){
        double Sum1 = 0, Sum2 = 0, num1 = 0, num2 = 0;
        for(int P = 0; P < n; ++P){
            if(Ch & (1 << P)){//Shop 1
                Sum1 += A1[P];
                num1++;
            }else{//Shop 2
                Sum2 += A2[P];
                num2++;
            }
        }
        return (Sum1 - ((num1 / 100) * Sum1)) + (Sum2 - ((num2 / 100) * Sum2));
    }
    for(int l = 0; l < n; ++l){
        Ans = min(Ans ,Solve(i + 1, Ch| (1 << l)));
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%lf", &A1[i]);
    }
    for(int i = 0; i < n; ++i){
        scanf("%lf", &A2[i]);
    }
    Solve(0, 0);
    printf("%.2f", Ans);
    

}
