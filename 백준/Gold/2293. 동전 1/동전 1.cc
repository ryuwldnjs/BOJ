#include <stdio.h>
int n, k;
int coin[105];
int dp[10005] = { 1 };
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];
	printf("%d", dp[k]);
}