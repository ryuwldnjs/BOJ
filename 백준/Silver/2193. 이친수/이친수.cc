#include <stdio.h>
int n;
long long dp[95];
int main()
{
	scanf("%d", &n);
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<=n;i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	printf("%lld", dp[n]);
	return 0;
}