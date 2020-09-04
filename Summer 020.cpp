#include <bits/stdc++.h>
using namespace std;
int n,m,t[15],stats,h,po,pep[100005];
bool inq[100005];
queue<int> q;

int Find(int num){
    for(int i=1;i<=m;++i){
        if(t[i] == num)
            return i;
    }
    return 0;
}

int Tempty(){
    for(int i=1;i<=m;++i){
        if(t[i] == 0)
            return i;
    }
    return 0;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n*2;i++){
        scanf("%d %d",&stats,&h);
        if(stats == 1){
           po = Tempty();
           if(po != 0){
                t[po] = h;
                inq[h] = false;
           }else{
                q.push(h);
                inq[h] = true;
           }
        }else{
            po = Find(h);
            if(po != 0){
                pep[h] = po;
                inq[h] = false;
                t[po] = 0;
            }else{
                pep[h] = 0;
                inq[h] = false;
            }

            po = Tempty();
            if(po != 0){
                while(!q.empty() and !inq[q.front()]){
                    q.pop();
                }
                if(!q.empty()){
                    t[po] = q.front();
                    inq[q.front()] = false;
                }
            }
        }

    }
    for(int i=1;i<=n;++i){
        printf("%d\n",pep[i]);
    }
    return 0;
}
