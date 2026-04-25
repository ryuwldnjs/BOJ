#include <stdio.h>
int dp[20]={2,3};
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		dp[i] = dp[i-1]+ (1<<i-1);
		
	printf("%d", dp[n]*dp[n]);
	return 0;
}