#include <iostream>
using namespace std; 
long long n,fibo[25]={0,1,1};
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
	cout<<fibo[n];
	return 0;
}