#include <iostream>
#include <algorithm>
using namespace std;

using ll=long long;
ll n,k, sum;

ll solve(ll num){
	ll cnt = 0;
	for(ll i=1;i<=n;i++){
		cnt += n*i <= num ? n : num/i;
	} // n보다 작거나 같은 숫자들의 개수
	return cnt; 
}
int main(){
	cin>>n>>k;
	
	ll l = 0, r = 2100000000;
	ll mid;
	
	for(int i=0;i<200;i++){
		mid = (l + r) / 2;
		ll tmp = solve(mid);
		if(tmp < k){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	cout<<mid;
	return 0;
}