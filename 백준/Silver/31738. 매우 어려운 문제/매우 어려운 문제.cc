#include <iostream>
using namespace std;
using ll=long long;
ll n,m;
int main(){
	cin>>n>>m;
	ll product = 1LL;
	for(int i=2;i<=n;i++){
		product *= i;
		product %= m;
		if(product == 0) break; 
	}
	cout<<product;
	return 0;
}