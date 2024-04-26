#include <iostream>
#define MOD 1000000009
using namespace std;
int t,n;
int dp[1000000+5] = {0,1,2,4,};
int main(){
	cin>>t;
	for(int i=4;i<1000000+5; i++){
		dp[i] = (dp[i]+dp[i-1])% MOD;
		dp[i] = (dp[i]+dp[i-2])% MOD;
		dp[i] = (dp[i]+dp[i-3])% MOD;
		
	}
	while(t--){
		cin>>n;
		cout<<dp[n]<<'\n';
	}
	return 0;
}