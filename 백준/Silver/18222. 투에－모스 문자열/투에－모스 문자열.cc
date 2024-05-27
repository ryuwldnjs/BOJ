#include <iostream>
using namespace std;
using ll=long long;
ll k, isReverse;
int main(){
	cin>>k;
	while(k != 1){
		
		ll tmp=1;
		for(;tmp*2 < k; tmp<<=1);
		k -= tmp;
		isReverse ^= 1;
	}
	if(isReverse) cout<<1;
	else cout<<0;
	return 0;
}