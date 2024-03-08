#include <iostream>
#define MOD 1000000007
using namespace std;
long long n,arr[500000+5], psum[500000+5],answer;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		psum[i] = psum[i-1] + arr[i];
	}
	for(int i=1;i<=n;i++){
		answer += arr[i] * (psum[n] - psum[i]);
		answer %= MOD;
	}
	cout<<answer;
	return 0;
}