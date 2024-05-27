#include<iostream>
#include <set>
using namespace std;
using ll=unsigned long long;
ll isCheck[(1<<25) / 64 + 1]; 
ll b;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while(cin>>b){
		ll idx = b / 64;
		ll bit = b % 64;
		if(isCheck[idx] & (1LL<<bit)) continue;
		cout<<b<<' ';
		isCheck[idx] |= (1LL<<bit);
	}
	return 0;
}