
#include<bits/stdc++.h>
using namespace std;

map<int,int> m, sum, save;
vector<int> po;

int main(){
    int M, Q;
    scanf("%d %d", &M ,&Q);

    for(int i = 1; i <= M; ++i){
        int l, r, x; scanf("%d %d %d", &l, &r, &x);
        m[l] += x;
        m[r + 1] -= x;
    }

    int tamp = 0;
    for(auto y : m){
        m[y.first] = y.second + tamp;
        tamp = m[y.first];
    }

    tamp = 0;
    int num = 0, total = 0;
    for(auto y : m){
        sum[y.first] = total + (tamp * (y.first - num));
        save[y.first - 1] = sum[y.first];
        po.push_back(y.first - 1);
        tamp = m[y.first];
        num = y.first;
        total = sum[y.first];
    }

    /*for(int i = 0; i < po.size(); ++i){
        printf("%d ", po[i]);
    }printf("\n");
    for(auto y : save){
        printf("(%d %d) ", y.first, y.second);
    }printf("\n");
    for(auto y : m){
        printf("(%d %d) ", y.first, y.second);
    }printf("\n");*/

    vector<int>::iterator po1, po2;
    for(int i = 1; i <= Q; ++i){
        int l, r; scanf("%d %d", &l, &r);
        l--;
        po1 = lower_bound(po.begin(), po.end(), l);
        po2 = lower_bound(po.begin(), po.end(), r);
        //printf("po1 = %d po2 = %d\n", po1 - po.begin(), po2 - po.begin());
        int sum1 = save[l], sum2 = save[r];


        if(po[po2 - po.begin()] != r){
            //cout << "in";
            sum2 = save[po[po2 - po.begin()]];
            sum2 -= (po[po2 - po.begin()] - r) * m[po[po2 - po.begin() - 1] + 1];
        }
        if(po[po1 - po.begin()] != l){
            sum1 = save[po[po1 - po.begin()]];
            sum1 -= (po[po1 - po.begin()] - l) * m[po[po1 - po.begin() - 1] + 1];

        }
        printf("%d\n",sum2 - sum1);
    }
    /*for(auto y : save){
        printf("(%d %d) ", y.first, y.second);
    }printf("\n");*/
    /*for(auto y : po){
        printf("%d ", y);
        //printf("(%d %d) ", y.first, y.second);
    }*/

    /*for(int i = 1; i <= 10; ++i){
        m[i] += m[i - 1];
    }*/

    /*for(int i = 1; i <= 10; ++i){
        printf("%d ", m[i]);
    }*/
}
