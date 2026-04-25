#include <stdio.h>
#define MOD 1000000000
int n,ans;
int dp[105][10];
int main()
{
	scanf("%d", &n);
	for(int i=1;i<=9;i++)
	{
		dp[1][i]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(j-1>=0)
			dp[i][j] += dp[i-1][j-1];
			if(j+1<=9)
			dp[i][j] +=dp[i-1][j+1];
			dp[i][j] %=MOD;
		}
	}
	
	for(int i=0;i<=9;i++)
	{
		ans +=dp[n][i];
		ans %=MOD;
	}
	printf("%d", ans);
	return 0;
}