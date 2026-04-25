#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
int map[1005][1005];
int dp[1005][1005];
int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + map[i][j];
		}
	}
	printf("%d", dp[n][m]);
	return 0;
}