#include <iostream>
using namespace std;
long long a,b,c;

long long solve(long long n){
	if(n==1) return a%c;
	if(n%2==0){
		long long tmp = solve(n/2);
		return ((tmp%c)*(tmp%c))%c;
	}
	else {
		long long tmp = solve(n/2);
		return (((tmp%c)*(tmp%c))%c*a)%c;
	}
	
	
}
int main(){
	cin>>a>>b>>c;
	
	cout<<solve(b);
	return 0;
}