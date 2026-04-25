#include <stdio.h>
int n, ans;
int dp[1005][10];
int main()
{
	for(int i=0;i<=9;i++)
	{
		dp[1][i]=1;
	}
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=j;k++)
			{
				dp[i][j] += dp[i-1][k];
				dp[i][j]%=10007;
			}
		}
	}
	
	for(int i=0;i<=9;i++)
	{
		ans += dp[n][i];
	}
	printf("%d", ans%10007);
	return 0;
}

// dp[n][k] = dp[n-1][0]~dp[n-1][k] 의 합 