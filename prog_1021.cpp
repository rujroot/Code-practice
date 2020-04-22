#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<long long int> v;
	int n,x;
	char c;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf(" %c",&c);
		if(c == 'P'){
			scanf("%d",&x);
			v.push_back(x);
			sort(v.begin(),v.end());
		}else{
			if(v.empty()){
				printf("-1\n");
			}
			else{
				printf("%d\n",v.back());
				v.pop_back();
			}
		}
	}
}
