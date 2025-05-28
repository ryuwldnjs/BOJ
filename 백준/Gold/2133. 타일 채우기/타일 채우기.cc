#include <stdio.h>
int n;
int dp[35] = { 1,0,3 };

int main()
{
	scanf("%d", &n);
	if (n % 2 != 0)
	{
		printf("0");
		return 0;
	}

	for (int i = 4; i <= n; i+=2)
	{
		dp[i] = 3 * dp[i - 2];
		for (int j = 2; 2*j <= i; j++)
			dp[i] += 2 * dp[i - 2 * j];
	}
	printf("%d", dp[n]);
	return 0;
}