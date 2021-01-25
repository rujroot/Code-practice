#include<bits/stdc++.h>
using namespace std;

double Ans = 9e18, A1[20], A2[20];
int n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%lf", &A1[i]);
    }
    for(int i = 0; i < n; ++i){
        scanf("%lf", &A2[i]);
    }
    
    for(int i = 0; i <= (1 << n) - 1; ++i){
        double Sum1 = 0, Sum2 = 0, num1 = 0, num2 = 0;
        for(int P = 0; P < n; ++P){
            if(i & (1 << P)){
                Sum1 += A1[P];
                num1++;
            }else{
                Sum2 += A2[P];
                num2++;
            }
        }
        Ans = min(Ans, (Sum1 - ((num1 / 100) * Sum1)) + (Sum2 - ((num2 / 100) * Sum2)));
    }

    printf("%.2f", Ans);
    return 0;

}
