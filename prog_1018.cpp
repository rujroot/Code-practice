
#include <bits/stdc++.h>
using namespace std;
bool can = true;
int x,y,distant,Currdir = 1;
char Direction[] = {'N','E','S','W'};
void walk(){
    char Direct = Direction[Currdir];
    if(Direct == 'N'){
        y += distant;
    }
    else if(Direct == 'E'){
        x += distant;
    }
    else if(Direct == 'S'){
        y -= distant;
    }
    else if(Direct == 'W'){
        x -= distant;
    }
    if(y >= 50000 || y <= -50000 || x >= 50000 || x <= -50000){
        can = false;
    }
}
void Turn(char command){
    if(command == 'R'){
        if(Currdir + 1 >= 4)
            Currdir = 0;
        else
            Currdir++;
    }
    else if(command == 'L'){
        if(Currdir - 1 < 0)
            Currdir = 3;
        else
            Currdir--;
    }
    else if(command == 'B'){
        if(Currdir - 2 < 0){
            Currdir += 2;
        }else{
            Currdir -= 2;
        }
    }
}
int main()
{
    string command;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        cin >> command;
        scanf("%d",&distant);
        Turn(command[0]);
        walk();
        //cout << command;
        //printf(" %d\n",distant);
    }
    if(can){
        printf("%d %d\n%c",x,y,Direction[Currdir]);
    }else{
        printf("DEAD");
    }

    return 0;
}
