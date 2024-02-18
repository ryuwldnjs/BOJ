#include <bits/stdc++.h>
#define MOD 998'244'353
using namespace std;
long long W,H,K,T,x,y;
long long answer=1;
int main(){
	cin>>W>>H>>K>>T;
	while(K--){
		cin>>x>>y;
		vector<long long> dis = {H-y, W-x, y-1, x-1}; //N,E,S,W
		for(long long &x : dis)
			x = min(x, T);
		answer *= ((dis[0]+dis[2]+1) * (dis[1]+dis[3]+1))%MOD;
		answer %= MOD;
	}
	cout<<answer;
	return 0;
}