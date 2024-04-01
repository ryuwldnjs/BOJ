#include <iostream>
#define MOD 1'000'000'009
using namespace std;
long long dp[100000+100][2]; //홀,짝 
int t,n;
int main(){
	cin>>t;
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[3][0] = 1;
	
	dp[2][1] = 1;
	dp[3][1] = 2;
	dp[4][1] = 3;
	dp[5][1] = 2;
	dp[6][1] = 1;
	
	int tmp[7] = {0,0,1,2,3,2,1};
	
	for(int i=1;i<=100000+5;i++){
		for(int idx=2;idx<=6;idx++){
			dp[i+idx][0] += (tmp[idx] * dp[i][0])%MOD;
			dp[i+idx][0] %= MOD;
			
			dp[i+idx][1] += (tmp[idx] * dp[i][1])%MOD;
			dp[i+idx][1] %= MOD;
			
			
		}
//		dp[i+2][0] += dp[i][0];
//		dp[i+3][0] += 2*dp[i][0];
//		dp[i+4][0] += 3*dp[i][0];
//		dp[i+5][0] += 2*dp[i][0];
//		dp[i+6][0] += dp[i][0];
//		
//		dp[i+2][1] += dp[i][1];
//		dp[i+3][1] += 2*dp[i][1];
//		dp[i+4][1] += 3*dp[i][1];
//		dp[i+5][1] += 2*dp[i][1];
//		dp[i+6][1] += dp[i][1];
		
	}
	
	while(t--){
		cin>>n;
		cout<<dp[n][0]<<' '<<dp[n][1]<<'\n';
	}
	return 0;
}