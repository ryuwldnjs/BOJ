#include <stdio.h>
#include <algorithm>
using namespace std;
int n, map[105][105];
int visited[105][105];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt, ans;
bool pass(int x, int y)
{
	if (x > 0 && y > 0 && x <= n&&y <= n)
		return true;
	return false;
}
void dfs(int x, int y)
{
	visited[x][y] = cnt;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (pass(xx, yy) && !visited[xx][yy])
		{
			dfs(xx, yy);
		}
	}
}
int main()
{
	int h=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
			h = max(h, map[i][j]);
		}

	for (int k = 0; k < h; k++) //서서히 물 차오름
	{
		cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] <= k) //물에 잠김
					visited[i][j] = 1;
				else
					visited[i][j] = 0;
			}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (!visited[i][j])//방문 안했을때
				{
					cnt++;
					dfs(i, j);
				}

		ans = max(ans, cnt);
	}
	printf("%d", ans);
	return 0;
}

