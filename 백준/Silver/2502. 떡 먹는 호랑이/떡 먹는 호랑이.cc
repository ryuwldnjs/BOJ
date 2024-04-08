#include <iostream>
using namespace std;
long long fibo[35]={0,1,};
int d,k;
int main(){
	cin>>d>>k;
	for(int i=2;i<=d;i++){
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	
	
	for(int i=1;i<=100000;i++){
		int j = (k - fibo[d-2]*i) / fibo[d-1];
		 
		if(i<j && fibo[d-2]*i + fibo[d-1]*j == k){
			cout<<i<<'\n'<<j;
			return 0;
		}
	}
	return 0;
}