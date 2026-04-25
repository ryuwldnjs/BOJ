#include <stdio.h> 

long long dp[105] = {0,1,1,1,2,2};
int main()
{
	int t,n; 
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		
		for(int i=6;i<=n;i++)
		{
			dp[i]=dp[i-1] + dp[i-5];
		}
		
		printf("%lld\n", dp[n]);
	}
	
	return 0;
}