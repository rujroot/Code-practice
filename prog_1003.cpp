#include<bits/stdc++.h>
using namespace std;
int Mem[150];
bool ch;
bool T(int num){
    if(num < 0){
        return false;
    }
    if(Mem[num] != -1){
        return Mem[num];
    }
    if(num == 6 or num == 9 or num == 20){
        return true;
    }
    return Mem[num] = T(num-6) or T(num-9) or T(num-20);
}
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<=num;++i){
        Mem[i] = -1;
    }
    for(int i=0;i<=num;++i){
        if(T(i)){
            ch = true;
            printf("%d\n",i);
        }
    }
    if(!ch){
        printf("no");
    }
    return 0;
}
