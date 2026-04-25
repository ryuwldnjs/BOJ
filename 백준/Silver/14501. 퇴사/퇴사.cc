#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int t[20];
int p[20];
int dp[20];
int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &t[i], &p[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
		for (int j = i+1; j <= n+1; j++)
			dp[j] = max(dp[j], dp[i]);
	}
	printf("%d", dp[n+1]);
	return 0;
}