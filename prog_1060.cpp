/*  1060 : Cromartie Mountain
    ST 19.39 15/5/63 ED : 20.21 15/5/63
    O(n^3)
    Rujroot
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,H=0,B=0,x,y,id;
    char MT[100][100];
    vector<pair<int,int>> v;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d %d",&x,&y);
        v.push_back({x,y});
        H = max(H,y);
       if(B < x){
            B = x;
            id = i;
       }
    }
    B = v[id].first + (v[id].second*2)-1;
    for(int i=0;i<H;++i){
        for(int j=0;j<B;++j){
            MT[i][j] = '.';
        }
    }
    for(int K=0;K<v.size();++K){
        int ST = v[K].first-1;
        int Sp = 0;
        for(int i=1;i<=v[K].second;++i){
            for(int j=0;j<(v[K].second*2) - (2*i) + 2;++j){
                if(j == 0){
                    if(MT[H-i][ST+j+Sp] == 92){
                        MT[H-i][ST+j+Sp] = 'v';
                    }else if(MT[H-i][ST+j+Sp] == '.'){
                        MT[H-i][ST+j+Sp] = '/';
                    }
                }else if(j == (v[K].second*2) - (2*i) + 1){
                    if(MT[H-i][ST+j+Sp] == '/'){
                        MT[H-i][ST+j+Sp] = 'v';
                    }else if(MT[H-i][ST+j+Sp] == '.'){
                        MT[H-i][ST+j+Sp] = 92;
                    }
                }else{
                    MT[H-i][ST+j+Sp] = 'X';
                }
            }
            Sp++;
        }
    }
    for(int i=0;i<H;++i){
        for(int j=0;j<B;++j){
            printf("%c",MT[i][j]);
        }
    }
    return 0;
}

