#include <bits/stdc++.h>
using namespace std;
bool Have(queue<int> current,int c){
    int siz = current.size();
    for(int i=0;i < siz;++i){
        if(current.front() == c){
            return true;
        }else{
            current.pop();
        }
    }
    return false;
}
int main()
{
    int Nc,Ns,x,y,st[1010];
    char A;
    scanf("%d %d",&Nc,&Ns);
    queue<int> q[Nc+5],cur;
    for(int i=0;i<Ns;++i){
        scanf("%d %d",&x,&y);
        st[y] = x;
    }
    while(true){
        scanf(" %c",&A);
        if(A == 'E'){
            scanf("%d",&x);
            q[st[x]].push(x);
            if(cur.empty()){
                cur.push(st[x]);
            }else{
                if(!Have(cur,st[x]))
                    cur.push(st[x]);
            }
        }else if(A == 'D'){
            if(cur.empty()){
                printf("empty\n");
            }
            else{
                printf("%d\n",q[cur.front()].front());
                q[cur.front()].pop();
                if(q[cur.front()].empty()){
                    cur.pop();
                }
            }
        }else{
            printf("0");
            break;
        }

    }
    return 0;
}
