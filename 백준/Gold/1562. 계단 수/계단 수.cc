#include <iostream>
#define MOD 1000000000
using namespace std;
int n;
int dp[105][10][1<<10];
int answer;
int main(){
	cin>>n;
	for(int i=1;i<10;i++){
		dp[0][i][1<<i] = 1;
	} 
	for(int i=1;i<n;i++){
//		dp[i][0] = dp[i-1][1];
//		dp[i][9] = dp[i-1][8];
//		for(int j=1;j<9;j++){
//			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%MOD;	
//		}
//		dp[i][0][k] = dp[i-1][1][]
		for(int k=0;k<1024;k++){
			dp[i][0][k | (1<<0)] = (dp[i][0][k | (1<<0)] + dp[i-1][1][k]) % MOD;
			dp[i][9][k | (1<<9)] = (dp[i][9][k | (1<<9)] + dp[i-1][8][k]) % MOD;
		}
		for(int j=1;j<9;j++){
			for(int k=0;k<1024;k++){
				dp[i][j][k | (1<<j)] = (dp[i][j][k | (1<<j)] + dp[i-1][j-1][k] + dp[i-1][j+1][k]) % MOD;
			}
		}
		
	}
	for(int i=0;i<=9;i++){
//		printf("%d\n", dp[n-1][i][1023]);
		answer = (answer + dp[n-1][i][1023]) % MOD;
	}
	printf("%d", answer);
	return 0;
}