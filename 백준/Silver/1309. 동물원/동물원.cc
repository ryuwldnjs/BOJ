#include <stdio.h>
#define MOD 9901
int dp[100000]={1,3,7,17,41};
int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i=3;i<=n;i++)
	{
		dp[i]= (2*dp[i-1]+dp[i-2])%MOD;
	}
	printf("%d", dp[n]);
	return 0;
}