#include <iostream>
#define MOD 1000000007

using namespace std;
using ll=long long;

ll answer;
ll m,n,s;

ll pow(ll x, ll exponent){
	ll answer = 1;
	while(exponent){
		if(exponent%2 == 1) answer = (answer * x) % MOD;
		x = (x*x) % MOD;
		exponent >>= 1;
	}
	return answer;
}
int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
int main(){
	cin>>m;
	while(m--){
		cin>>n>>s;
		ll a = s / gcd(n,s);
		ll b = n / gcd(n,s);
		ll inverse_b = pow(b, MOD-2); // 페르마 소 정리.. 
		answer = (answer + a*inverse_b % MOD) % MOD;
//		cout<<inverse_b; 
	}
	cout<<answer;
	return 0;
}