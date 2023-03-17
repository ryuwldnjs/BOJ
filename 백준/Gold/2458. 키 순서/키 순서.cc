#include <stdio.h>
#include <algorithm>
#define INF 987654321
using namespace std;
int a, b;
int ans;
int map[505][505];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
				map[i][j] = INF;
		}
	}


	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		map[a][b] = 1; // 키가a<b
	}


	//플로이드
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
	int ans=0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] != INF || map[j][i] != INF)
				cnt++;
		}
		if (cnt == n )
			ans++;
	}
	printf("%d", ans);
	return 0;
}