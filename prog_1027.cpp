/*  1027 : SMS
    ST : 17.15 22/4/2563 ED : 19.28 22/4/2563
    O(n^2)
    Rujroot
*/

#include <bits/stdc++.h>
using namespace std;
map<char,int> m;
map<char ,int>::iterator it;
vector<pair<int,char>> v;
bool Sort(const pair<int,char> &a,const pair<int,char> &b){
    return(a.first > b.first);
}
int main()
{
    for(int i=0;i<7;++i){
        m.insert({'A'+i,0});
    }
    while(true){
        string vote;
        cin >> vote;
        if(vote == "!"){
            break;
        }
        v.clear();
        for(int i=0;i<vote.size();++i){
            it = m.find(vote[i]);
            if(it != m.end())
                m[vote[i]]++;
        }
        for(auto x:m){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        if(v.size() != 1 and v[0].first != v[1].first){
            m.erase(v[0].second);
            v.erase(v.begin());
        }
    }
    sort(v.begin(),v.end(),Sort);
    printf("%d\n",v.size());
    for(int i=0;i<v.size();++i){
        printf("%c %d\n",v[i].second,v[i].first);
    }
    return 0;
}

//-------------<comment>------------------//
/*for(auto x : m){
        cout << x.first << " " << x.second << "\n";
    }*/
/*vector<pair<char,int>> vs;
    for(int i=0;i<v.size();++i){
        vs.push_back({v[i].second,v[i].first});
    }*/
   /*for(int i=0;i<v.size()-1;++i){
        if(v[i].first == v[i+1].first and v[i].second < v[i+1].second){
            pair<int,char> tmp = {v[i].first,v[i].second};
            v[i] = v[i+1];
            v[i+1] = tmp;
        }
    }*/
    //sort(v.begin(),v.end());

