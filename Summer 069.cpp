#include <bits/stdc++.h>
using namespace std;
int num1[10010], num2[10010], Ans[10010];
int main()
{
    string n1, n2;
    cin >> n1;
    cin >> n2;
    int Max = max(n1.size(), n2.size());
    for (int i = 1; i <= n1.size(); ++i){
        num1[n1.size() - i + 1] = n1[i - 1] - 48;
    }
    for (int i = 1; i <= n2.size(); ++i){
        num2[n2.size() - i + 1] = n2[i - 1] - 48;
    }
    for(int i = 1;i <= Max; ++i){
        int Plus;
        Plus = num1[i] + num2[i];
        if(Plus >= 10){
            Ans[i] += Plus - 10;
            Ans[i + 1]++;
        }else{
            Ans[i] += Plus;
        }
        if(Ans[i] >= 10){
            Ans[i + 1]++;
            Ans[i] -= 10;
        }
    }
    if (Ans[Max + 1] != 0)
            printf("%d",Ans[Max + 1]);
    for(int i = Max;i >= 1; --i){
        printf("%d",Ans[i]);
    }
    return 0;
}
