#include <iostream>
using namespace std;
int t,a,b;

int gcd(int x, int y){
	return x%y == 0 ? y : gcd(y, x%y);
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<a*b/gcd(a,b)<<"\n";
	}
	return 0;
}