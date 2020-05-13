/*  1059 : SMS Thumb
    ST : 18.42 13/5/63 ED : 19.56 13/5/63
    O(n)
    Rujroot
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<char> v[15];
    string s;
    char Char = 'A';
    int N,S,M,Po[15],Ref[5][5],H,V,Push,Row,Cal,Value;
    pair<int,int> Curr;
    for(int i=2;i<10;++i){
        if(i == 7 or i == 9){
            Po[i] = 4;
            for(int j=0;j<4;++j){
                v[i].push_back(Char);
                Char++;
            }
        }else{
            Po[i] = 3;
            for(int j=0;j<3;++j){
                v[i].push_back(Char);
                Char++;
            }
        }
    }
    scanf("%d %d %d",&N,&S,&M);
    if(S != 1)
        s.push_back(v[S][(M-1)%Po[S]]);
    int num = 1;
    for(int i=1;i<=3;++i){
       for(int j=1;j<=3;++j){
            if(S == num){
                Curr = {i,j};
            }
            Ref[i][j] = num;
            num++;
        }

    }
    for(int i=0;i<N-1;++i){
        scanf("%d %d %d",&H,&V,&Push);
        Curr = {Curr.first + V,Curr.second + H};
        Row = Curr.first , Cal = Curr.second;
        Value = Ref[Row][Cal];
        if(Value != 1){
            s.push_back(v[Value][(Push-1)%Po[Value]]);
        }
        else{
            while(!s.empty() and Push--){
                s.pop_back();
            }
        }
    }
    if(s.empty()){
        printf("null");
        return 0;
    }
    cout << s;
    return 0;
}

