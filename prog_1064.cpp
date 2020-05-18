/*  1064 : Cromartie School
    ST : 21.12 17/5/63 ED : 22.43 18/5/63
    O(n^4)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int W,L,ST,pond;
string s[100],tmps[100];
set<int> Set;
void Tom(int i,int j){
    Set.insert(i);
    s[i][j] = 'S';
    if(i+1 < L and s[i+1][j] == 'P'){
        Tom(i+1,j);
    }
    if(i-1 >= 0 and s[i-1][j] == 'P'){
        Tom(i-1,j);
    }
    if(j+1 < W and s[i][j+1] == 'P'){
        Tom(i,j+1);
    }
    if(j-1 >= 0 and s[i][j-1] == 'P' ){
        Tom(i,j-1);
    }
}
int Can(int n,int m){
    int num = 0;
    for(int i = n;i<n+ST;++i){
        for(int j = m;j<m+ST;++j){
            if(s[i][j] == 'T'){
                return -1;
            }else if(s[i][j] == 'P'){
                Tom(i,j);
                num++;
            }
        }
    }
    return num;
}
int main()
{
    scanf("%d %d",&W,&L);
    ST = min(W,L);
    for(int i=0;i<L;++i){
        cin >> s[i];
        tmps[i] = s[i];
    }
    bool Have = false;
    while(true){
        int Min = 2e9;
        for(int i=0;i<=L-ST;++i){
            for(int j=0;j<=W-ST;++j){
                pond = Can(i,j);
                if(pond != -1){
                    Have = true;
                    Min = min(Min,pond);
                }
                for(auto x : Set){
                    s[x] = tmps[x];
                }
                Set.clear();
            }
        }
        if(Have){
            printf("%d %d",ST*ST,Min);
            break;
        }
        ST--;
        if(ST <= 0){
            printf("0 0");
            break;
        }
    }
    return 0;
}

