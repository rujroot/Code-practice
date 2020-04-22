#include <bits/stdc++.h>
using namespace std;
int power(long long int n,long long int p){
    long long int ans = 1;
    if(p == 0){
        return 1;
    }else{
    for(int i=0;i<p;++i){
        ans = ans*10;
        }
    return ans;
    }

}
int main()
{

    long long int num[5],ck,G[5];
    G[0] = 0;
    G[1] = 0;
    scanf("%lld %lld",&num[0],&num[1]);
    getchar();
    string Ans[5][5];
    for(int i=0;i<2;++i){
      for(int j=0;j<3;++j){
        getline(cin,Ans[i][j]);
      }
    }
    for(int k=0;k<2;++k){
       for(int i=0;i<num[k];++i){
            ck = (num[k]*4-3)-(i*4);
            //printf("Ck = %d",ck);
            if(Ans[k][1][ck+1] == '|' and Ans[k][2][ck+1] == '|' and Ans[k][0][ck] != '_' and Ans[k][1][ck] != '_'){
               // printf("1");
                G[k] += 1*power(10,i) ;
            }
            else if(Ans[k][1][ck+1] == '|' and Ans[k][1][ck] == '_' and Ans[k][1][ck-1] != '|' and Ans[k][2][ck-1] == '|'){
               // printf("2");
                G[k] += 2*power(10,i);
            }
            else if(Ans[k][0][ck] == '_' and Ans[k][1][ck] == '_' and Ans[k][2][ck] == '_' and Ans[k][1][ck-1] != '|'){
               // printf("3");
                G[k] += 3*power(10,i);
            }
            else if(Ans[k][1][ck] == '_' and Ans[k][2][ck] != '_'){
                //printf("4");
                G[k] += 4*power(10,i);
            }
            else if(Ans[k][1][ck+1] != '|' and Ans[k][2][ck-1] != '|'){
                //printf("5");
                G[k] += 5*power(10,i);
            }
            else if(Ans[k][1][ck+1] != '|' and Ans[k][2][ck-1] == '|'){
               // printf("6");
                G[k] += 6*power(10,i);
            }
            else if(Ans[k][0][ck] == '_' and Ans[k][2][ck] != '_'){
               // printf("7");
                G[k] += 7*power(10,i);
            }
            else if(Ans[k][2][ck-1] == '|' and Ans[k][2][ck+1] == '|' and Ans[k][1][ck] == '_' and Ans[k][1][ck+1] == '|'){
               // printf("8");
                G[k] += 8*power(10,i);
            }
            else if(Ans[k][2][ck-1] != '|' and Ans[k][2][ck] == '_' and Ans[k][1][ck+1] == '|'){
                //printf("9");
                G[k] += 9*power(10,i);
            }else{
                //printf("0");
            }

        }
        //printf("\n");
    }
    //printf(" %d\n",pow(10,2));
   printf("%lld",G[0]+G[1]);
    return 0;
}
