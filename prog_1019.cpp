
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string DNA[5],Ans;
    int select = 1,notselect = 0,Max=0,End = 0;
    for(int i=0;i<2;++i){
        cin >> DNA[i];
    }
    /*if(DNA[0].size() >= DNA[1].size()){
        select = 1;
        notselect = 0;
    }*/
    for(int i=0;i<DNA[0].size();++i){
        for(int j=0;j<DNA[1].size();++j){
            if(DNA[0][i] == DNA[1][j]){
                //printf("%d %d\n",i,j);
                int check = 1;
                for(int k=0;k<=DNA[1].size();++k){
                    if(i+k > DNA[0].size()-1 or j+k > DNA[1].size()-1 or DNA[0][i+k] != DNA[1][j+k]){
                        //if(i == 4 and j == 0)
                        //    printf("j+k = %d\n",j+k);
                        End = j+k;
                        break;
                    }else{
                        /*if(i == 4 and j == 0){
                            printf("jj == %d i = %d j = %d ch = %d Max = %d\n",j,i+k,j+k,check,Max);
                        }*/
                        check++;
                    }
                }
                if(check > Max){
                        /*if(i == 4 and j == 0){
                            printf("\n\n%d %d\n\n",j,End);
                        }*/
                            Ans.clear();
                            //printf("%d %d %d %d\n",i,j,check,Max);
                            Ans = string(&DNA[1][j] ,&DNA[1][End]);
                            Max = check;
                }
            }
        }

    }
    cout << Ans;
    return 0;
}
