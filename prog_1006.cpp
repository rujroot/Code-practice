#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    char S;
    scanf("%d",&num);
    string N[num+5];
    for(int i=0;i<num;++i){
        cin >> N[i];
    }
    for(int i=0;i<num;++i){
        int Dice[10] = {1,2,3,5,4,6},CurrDice[10] = {1,2,3,5,4,6};
        for(int j=0;j<N[i].size();++j){
            S = N[i][j];
            if(S == 'F'){
                Dice[0] = CurrDice[3];
                Dice[1] = CurrDice[0];
                Dice[3] = CurrDice[5];
                Dice[5] = CurrDice[1];
                CurrDice[0] = Dice[0];
                CurrDice[1] = Dice[1];
                CurrDice[2] = Dice[2];
                CurrDice[3] = Dice[3];
                CurrDice[4] = Dice[4];
                CurrDice[5] = Dice[5];
            //
            }else if(S == 'B'){
                Dice[0] = CurrDice[1];
                Dice[1] = CurrDice[5];
                Dice[3] = CurrDice[0];
                Dice[5] = CurrDice[3];
                CurrDice[0] = Dice[0];
                CurrDice[1] = Dice[1];
                CurrDice[2] = Dice[2];
                CurrDice[3] = Dice[3];
                CurrDice[4] = Dice[4];
                CurrDice[5] = Dice[5];
            //
            }else if(S == 'L'){
                Dice[0] = CurrDice[4];
                Dice[2] = CurrDice[0];
                Dice[4] = CurrDice[5];
                Dice[5] = CurrDice[2];
                CurrDice[0] = Dice[0];
                CurrDice[1] = Dice[1];
                CurrDice[2] = Dice[2];
                CurrDice[3] = Dice[3];
                CurrDice[4] = Dice[4];
                CurrDice[5] = Dice[5];
            //
            }else if(S == 'R'){
                Dice[0] = CurrDice[2];
                Dice[2] = CurrDice[5];
                Dice[4] = CurrDice[0];
                Dice[5] = CurrDice[4];
                CurrDice[0] = Dice[0];
                CurrDice[1] = Dice[1];
                CurrDice[2] = Dice[2];
                CurrDice[3] = Dice[3];
                CurrDice[4] = Dice[4];
                CurrDice[5] = Dice[5];

            }else if(S == 'C'){
                Dice[1] = CurrDice[4];
                Dice[2] = CurrDice[1];
                Dice[3] = CurrDice[2];
                Dice[4] = CurrDice[3];
                CurrDice[0] = Dice[0];
                CurrDice[1] = Dice[1];
                CurrDice[2] = Dice[2];
                CurrDice[3] = Dice[3];
                CurrDice[4] = Dice[4];
                CurrDice[5] = Dice[5];
            }else if(S == 'D'){
                Dice[1] = CurrDice[2];
                Dice[2] = CurrDice[3];
                Dice[3] = CurrDice[4];
                Dice[4] = CurrDice[1];
                CurrDice[0] = Dice[0];
                CurrDice[1] = Dice[1];
                CurrDice[2] = Dice[2];
                CurrDice[3] = Dice[3];
                CurrDice[4] = Dice[4];
                CurrDice[5] = Dice[5];
            }
        }
        printf("%d ",Dice[1]);
    }
    return 0;
}
