
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    string input;
    double x=0,y=0,Ans=0;
    while(true){
        scanf("%d",&num);
        cin >> input;
        if(input == "*"){
            break;
        }
        /*printf("%d",num);
        cout << input;
        printf(" ");*/
        if(input.size() > 1){
            if(input == "NE"){
                x += (num * sqrt(2)/2);
                y += (num * sqrt(2)/2);
            }else if(input == "SE"){
                x += (num * sqrt(2)/2);
                y -= (num * sqrt(2)/2);
            }else if(input == "SW"){
                x -= (num * sqrt(2)/2);
                y -= (num * sqrt(2)/2);
            }else if(input == "NW"){
                y += (num * sqrt(2)/2);
                x -= (num * sqrt(2)/2);
            }
        }else{
            if(input == "N"){
                y += num;
            }else if(input == "E"){
                x += num;
            }else if(input == "S"){
                y -= num;
            }else if(input == "W"){
                x -= num;
            }
        }
    }
    printf("%.3f %.3f",x,y);
    printf("\n%.3f",sqrt(-x*-x + -y*-y));
    return 0;
}
