#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    pair<int, int> Ans = {1, 0};
    scanf("%d", &n);
    vector<int> D, B;
    for (int i = 0; i < n; ++i){
        int num; scanf("%d", &num);
        D.push_back(num);
    }
    for (int i = 0; i < n; ++i){
        int num; scanf("%d", &num);
        B.push_back(num);
    }
    for(int i = 0; i < n; ++i){
        int Energy = B[i], Po = i, C = 0;
        //printf("%d : ", i);
        while(true){
          // printf("%d ", Po);
            Energy -= D[Po];
            Po++;
            if(Po == n){
                Po = 0;
            }
            if(Energy < 0){
                if(C > Ans.first){
                    Ans = {C , i};
                }
                if(C == Ans.first and i < Ans.second){
                    Ans = {C , i};
                }
                break;
            }
            if(Po == i){
                if(n > Ans.first){
                    Ans = {n , i};
                }
                if(n == Ans.first and i < Ans.second){
                    Ans = {n , i};
                }
                break;
            }

            Energy += B[Po];
            C++;
        }//printf("\n");
    }
    printf("%d %d", Ans.first, Ans.second + 1);
    return 0;
}
