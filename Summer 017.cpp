#include <bits/stdc++.h>
#include "number.h"
using namespace std;
int solve(){
    int l = 1,r = 100,c = 0,ch;
        while(l <= r and r != l+1){
        ch = l + (r-l) / 2;
        c++;
        if(check(ch))
            r = ch;
        else
            l = ch ;
        }
    if(r == 2 and check(1))
        return 1;
    else
        return r;
}
