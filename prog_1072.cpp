/*  1072 : number
    ST : 14.50 31/5/63 ED : 17.05 31/5/63
    O(m+n)
    rujrooot
*/
#include <bits/stdc++.h>
using namespace std;
int N,M,r = 1,po = 0,x,y,pox,poy,tmp;
char c;
vector<int> v;
int Getpo(int num){
    num--;
    num = po + (r * num);
    if(num < 0){
        num += N;
    }
    if(num >= N){
        num -= N;
    }
    return num;
}
int main()
{

    scanf("%d %d",&N,&M);
    for(int i=0;i<N;++i){
        scanf("%d",&x);
        v.push_back(x);
    }
    for(int i=0;i<M;++i){
        scanf(" %c",&c);
        if(c == 'a'){
            scanf("%d %d",&x,&y);
            pox = Getpo(x),poy = Getpo(y);
            tmp = v[pox];
            v[pox] = v[poy];
            v[poy] = tmp;
        }else if(c == 'b'){
            scanf("%d %d",&x,&y);
            pox = Getpo(x);
            v[pox] = y;
        }else if(c == 'c'){
            scanf("%d",&x);
            po += r * (x-1);
            r *= -1;
            if(po < 0){
                po += N;
            }else if(po >= N){
                po -= N;
            }
        }else{
            scanf("%d",&x);
            printf("%d\n",v[Getpo(x)]);
        }
    }
    return 0;
}

