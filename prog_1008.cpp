#include <bits/stdc++.h>
using namespace std;
bool sky[3100][3100];
int ed,hg;
void GD(int,int),GL(int,int),GLF(int),GU(int,int);
void GD(int i,int j){
    for(int k=0;k<hg;++k){
        if(i-k-1 == 0 and !sky[i-k-1][j+1]){
            printf("%d ",i-k-1);
            GLF(j);
            break;
        }//-----------------------------------------------------------
        else if(sky[i-k-1][j+1]){
            printf("%d ",i-k);
            GL(i-k-1,j);
            break;
        }
    }
}// 10 1
void GL(int i,int j){
    for(int k=0;k<=ed;++k){
        if(i != 0 and !sky[i][j+k+1]){
            printf("%d ",j+k+1);
            GD(i,j+k);
            break;
        }else if(i == 0 and !sky[i][j+k+1]){
            printf("%d ",j+k+1);
            GLF(j+k);
            break;
        }else if(sky[i+1][j+k+1]){
            printf("%d ",j+k+1);
            GU(i,j+k+1);
            break;
        }
    }

}
void GU(int i,int j){
    for(int k=0;k<hg;++k){
        //printf("%d %d\n",i+k+1,j);
        if(!sky[i+k+1][j]){
            printf("%d ",i+k+1);
            //printf("go => %d %d",i+k,j);
            GL(i+k,j);
            break;
        }
    }
}
void GLF(int j){
    for(int k=0;k<ed;++k){
        if(k+j+1 > ed){
            break;
        }else if(sky[0][j+k+1]){
            printf("%d ",j+k+1);
            GU(0,j+k+1);
            break;
        }
    }
}
int main()
{

    int num,x,y,z;
    scanf("%d",&num);
    vector<pair<pair<int,int>,int>> v;
    for(int i=0;i<num;i++){
        scanf("%d %d %d",&x,&y,&z);
        v.push_back({{x,z},y});
        ed = max(ed,z);
        hg = max(hg,y);
    }
    for(int i=0;i<v.size();++i){
        int L,R,H;
        L = v[i].first.first;
        R = v[i].first.second;
        H = v[i].second;
        for(int j=0;j<H;++j){
            for(int k=L;k<R;++k){
                sky[j][k] = true;
            }
        }
    }
    GLF(0);
    /*printf("\n");
    for(int i=0;i<hg;++i){
        for(int j=0;j<ed;++j){
            if(sky[i][j]){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }*/
    return 0;
}
