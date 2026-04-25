#include <iostream>
using namespace std;
int n,arr[100000+5];
int psum[100000+5];
long long answer;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		psum[i] = psum[i-1] + arr[i];
	}
	
	for(int i=1;i<=n;i++){
		long long rest = psum[n] - psum[i];
		answer += arr[i] * rest;
	}
	cout<<answer;
	return 0;
}