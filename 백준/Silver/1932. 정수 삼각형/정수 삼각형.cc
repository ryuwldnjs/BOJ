#include <stdio.h>
#include <algorithm>
using namespace std;
int n, ans, map[505][505];
int dp[505][505];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &map[i][j]);


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + map[i][j];

	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[n][i]);

	printf("%d", ans);
	return 0;
}