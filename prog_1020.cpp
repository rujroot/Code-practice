#include <bits/stdc++.h>
using namespace std;
int main()
{
    //printf("%d %d %d",'A','Z','a');
    string s,halff,halfb;
    int SizeS;
    cin >> s;
    SizeS = s.size();
    for(int i=0;i<SizeS;++i){
        if(s[i] >= 65 and s[i]<= 90){
            s[i] += 32;
        }
    }
    if(SizeS % 2 == 0){
        halff = string(&s[0],&s[SizeS/2]);
        halfb = string(&s[SizeS/2],&s[SizeS]);
    }
    else{
        halff = string(&s[0],&s[SizeS/2]);
        halfb = string(&s[SizeS/2+1],&s[SizeS]);
    }
    if(halff == halfb){
        printf("Double Palindrome");
        return 0;
    }
    //cout << halff << "\n" << halfb;
    for(int i=0;i<halff.size();++i){
        if(halff[i] != halfb[halff.size()-i-1]){
            //printf("i = %d ii = %d\n",i,halff.size()-i-1);
            printf("No");
             return 0;
        }
    }
    printf("Palindrome");


    //cout << "Hello world!" << endl;
    return 0;
}
