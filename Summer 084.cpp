#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<string> Save;
    string s;
    for (int i = 0; i < n; ++i){
        int c; scanf("%d" , &c);
        if(c == 1){
            Save.push_back(s);
            string inps;
            cin >> inps;
            s = s + inps;

        }
        else if(c == 2){
            Save.push_back(s);
            int x; scanf("%d", &x);
            int Size = s.size();
            for(int i = Size - 1; i >= Size - x; --i){
                s.pop_back();
            }
        }
        else{
            s = Save.back();
            Save.pop_back();
        }
        cout << s << "\n";
    }
    return 0;
}
