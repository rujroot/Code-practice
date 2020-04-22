
#include <bits/stdc++.h>
using namespace std;
int kab[20][20],n,can=0;
bool kabch[20][20];
vector<pair<int,int>> v;
int ispat(){
    //bool Found = false;
    int i1=v[0].first,i2=v[1].first,i3=v[2].first,j1=v[0].second,j2=v[1].second,j3=v[2].second;
    if(i1 == i2 and i2 == i3){
        return 0;
    }
    if(j1 == j2 and j2 == j3 ){
        return 0;
    }
    can++;
    /*if(!Found and ( (  and and ) or ( and and ) or ( and and ) )){

    }
    if(!Found and ( ( and and ) or ( and and ) or ( and and ) )){

    }
    if(!Found and ( ( and and ) or ( and and ) or ( and and ) )){

    }
    if(!Found and ( ( and and ) or ( and and ) or ( and and ) ))*/
}
void findA(int i,int j,int a){
    kabch[i][j] = true;
    v.push_back({i,j});
    if(i+1 < n and kab[i+1][j] == a and !kabch[i+1][j]){
        findA(i+1,j,a);
    }
    if(i-1 >= 0 and kab[i-1][j] == a and !kabch[i-1][j]){
        findA(i-1,j,a);
    }
    if(j+1 < n and kab[i][j+1] == a and !kabch[i][j+1]){
        findA(i,j+1,a);
    }
    if(j-1 >= 0 and kab[i][j-1] == a and !kabch[i][j-1]){
        findA(i,j-1,a);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&kab[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(!kabch[i][j]){
                v.clear();
                findA(i,j,kab[i][j]);
                if(v.size() == 3){
                    ispat();
                }
               /* for(int k=0;k<v.size();k++){
                    printf("{%d %d} ",v[k].first,v[k].second);
                }
                printf("\n");*/
            }
        }
    }
    printf("%d",can);
    return 0;
}
