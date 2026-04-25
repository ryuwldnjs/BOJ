#include <stdio.h>
int t, a, b;
int dp[35][35];

int main(){
	scanf("%d", &t);
	// 전처리 
	for(int i=0;i<=30;i++){
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		// nCr = n-1Cr-1 + n-1Cr --파스칼 
	}
	
	while (t--){
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[b][a]);
	}
	return 0;
}