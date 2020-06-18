/*  1094 : MJEHURIC
    ST : 17.39 18/6/63
    Read : 17.40 - 17.43 : 3 Min
    ED : 17.50
    Total : 11 Min
    O(n^2)
    Rujroot
*/
#include <iostream>
using namespace std;
int arr[10],tmp;
bool Sort(){
    for(int i=1;i<=5;++i){
        if(arr[i] != i)
            return false;
    }
    return true;
}
void printArr(){
    for(int i=1;i<=5;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    scanf("%d %d %d %d %d",&arr[1],&arr[2],&arr[3],&arr[4],&arr[5]);
    while(!Sort()){
        for(int i=1;i<=4;++i){
            if(arr[i] > arr[i+1]){
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                printArr();
            }
        }
    }
    return 0;
}

