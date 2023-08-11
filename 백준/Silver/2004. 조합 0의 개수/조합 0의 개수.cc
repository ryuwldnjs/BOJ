#include <iostream>
using namespace std;
long long five, two;
long long n,m;
int main(){
	
	cin>>n>>m;
	long long p = n-m;
	
	
	for(long long i=5;n/i;i*=5){
		five += n / i;
		five -= m / i;
		five -= p / i;
	}
	for(long long i=2;n/i;i*=2){
		two += n / i;
		two -= m / i;
		two -= p / i;
	}
	
	cout<<min(two, five);
	return 0;
}