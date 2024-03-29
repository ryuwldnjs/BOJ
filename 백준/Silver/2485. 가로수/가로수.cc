#include <iostream>
using namespace std;
int n,arr[100000+5];
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int GCD = arr[1]-arr[0];
	for(int i=1;i<n;i++){
		GCD = gcd(GCD, arr[i]-arr[i-1]);
	}
	
	cout<<(arr[n-1]-arr[0])/GCD  - n + 1;
	return 0;
}