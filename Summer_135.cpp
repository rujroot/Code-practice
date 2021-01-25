//ST : 22.12 25/1/64
//ED : 23.51 25/1/64
#include<bits/stdc++.h>
using namespace std;

double Ans = 9e18, A1[20], A2[20];
int n;

double Solve(int i, double Sum1, double Sum2, double num1, double num2){
    if(i >= n){

        return Ans = min(Ans, (Sum1 - ((num1 / 100) * Sum1)) + (Sum2 - ((num2 / 100) * Sum2)));
    }
    Solve(i + 1 , Sum1 + A1[i] ,Sum2, num1 + 1, num2);
    Solve(i + 1, Sum1, Sum2 + A2[i], num1, num2 + 1);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%lf", &A1[i]);
    }
    for(int i = 0; i < n; ++i){
        scanf("%lf", &A2[i]);
    }
    Solve(0, 0, 0, 0, 0);
    printf("%.2f", Ans);
    

}