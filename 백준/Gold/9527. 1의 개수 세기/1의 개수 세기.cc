#include<iostream>
using namespace std;

long long a,b,sum_a, sum_b;
int main(){
	cin>>a>>b;
	
	long long div=2;
	while(1){
		sum_a += a/div*(div/2);
		sum_a += max(a%div - div/2, 0LL);
		
		if(a/div==0) break;
		div *= 2;
	}
	div=2;
	while(1){
		sum_b += (b+1)/div*(div/2);
		sum_b += max((b+1)%div - div/2, 0LL);
		
		if((b+1)/div==0) break;
		div *= 2;
	}
	cout<<sum_b-sum_a;
	return 0;
} 