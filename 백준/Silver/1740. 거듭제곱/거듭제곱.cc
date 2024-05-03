#include <iostream>
using namespace std;
long long val[45]={1};
long long n;

int main(){
	cin>>n;
	for(long long i=1;i<45;i++) val[i] = val[i-1] * 3;
	
	long long sum = 0;
	for(long long j=0;j<45;j++){
		if(n & (1LL<<j)) sum += val[j];
	}
	
	cout<<sum;
	return 0;
}