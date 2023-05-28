#include <iostream>
using namespace std;
using ll=long long;
int n;
ll arr[100000+5], psum[100000+5], ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		psum[i] = psum[i-1] + arr[i];
	}
	
	for(int i=1;i<n;i++){
		ll tmp = arr[i] * (psum[n] - psum[i]);
		ans += tmp;
	}
	cout<<ans;
	return 0;
}