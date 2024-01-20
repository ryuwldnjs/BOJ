#include <iostream>
using namespace std;
long long n, dp[35];
int main(){
	dp[0] = 1;
	for(int i=1;i<31;i++){
		dp[i] = dp[i-1]*(4*i-2) / (i+1);
	}
	while(true){
		cin>>n;
		if(!n) break;
		cout<<dp[n]<<'\n';
	}
	return 0;
}