#include <stdio.h>
#include <algorithm>
using namespace std;
long long dp[105][105];
int map[105][105];
int main()
{
	dp[1][1]=1;
	int n, cnt=0;
	int jump; //점프 거리
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] == 0 || (i >= n && j >= n)) //불가능한 길,맵 제한
				continue;
			jump = map[i][j];
			if (i + jump <= n) // +x 방향
				dp[i + jump][j] += dp[i][j];
			if (j + jump <= n) // -y방향
				dp[i][j + jump] += dp[i][j];
		}
	}

	printf("%lld", dp[n][n]);
	return 0;
}

