#include <stdio.h>
#define MOD 15746
int n;
int dp[1000000+10]={0,1,2};
int main(){
	scanf("%d", &n);
	for(int i=3;i<=n;i++){
		dp[i] = (dp[i-1]+dp[i-2])%MOD;
	}
	printf("%d", dp[n]);
	return 0;
}