#include <stdio.h>
int dp[10 + 10] = { 0,1,2,4 };

int main()
{
	int n, k;
	scanf("%d", &n);

	for (int i = 4; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		printf("%d\n",dp[k]);
	}
	return 0;
}