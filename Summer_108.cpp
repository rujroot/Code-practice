#include<bits/stdc++.h>
using namespace std;

int DP[2021][2021];
string ans;

int main(){
    char s1[2021], s2[2021];
    int Ls1, Ls2;
    scanf("%s %s", s2 + 1, s1 + 1);

    Ls1 = strlen(s1 + 1), Ls2 = strlen(s2 + 1);

    for(int i = 1; i <= Ls1; ++i){
        for(int j = 1; j <= Ls2; ++j){
            if(s1[i] == s2[j])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
        }
    }
    int inx = DP[Ls1][Ls2];
    char lcs[inx + 1];
    int i = Ls1, j = Ls2;
    while (i > 0 && j > 0)
   {
      if (s1[i-1] == s2[j-1])
      {
          lcs[inx-1] = s1[i-1];
          i--; j--; inx--;
      }
      else if (DP[i-1][j] >= DP[i][j-1])
         i--;
      else
         j--;
   }

    //cout << ans;
    for(int i = 0; i < DP[Ls1][Ls2]; ++i){
        printf("%c", lcs[i]);
    }
}
