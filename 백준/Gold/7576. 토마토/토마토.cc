#include <stdio.h>
#include <queue>
using namespace std;
int map[1010][1010];
int check[1010][1010];
struct xy //xy좌표
{
	int x,y;
};
queue <xy> q;
void bfs()
{
	while (!q.empty())//큐가 빌때까지
	{
		//printf("%d %d\n", q.front().x, q.front().y);
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (map[x-1][y] == 0 && check[x-1][y] == -1)
		{
			q.push({ x-1,y });
			check[x - 1][y] = check[x][y] + 1;
		}
		if (map[x+1][y] == 0 && check[x+1][y] == -1)
		{
			q.push({ x+1,y });
			check[x + 1][y] = check[x][y] + 1;
		}
		if (map[x][y-1] == 0 && check[x][y-1] == -1)
		{
			q.push({ x,y-1 });
			check[x][y-1] = check[x][y] + 1;
		}
		if (map[x][y+1] == 0 && check[x][y+1] == -1)
		{
			q.push({ x,y+1 });
			check[x][y+1] = check[x][y] + 1;
		}
	}
}
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
			check[i][j] = -1;
			if (map[i][j] == 1)//익은 토마토
			{
				check[i][j] = 0;
				q.push({ i, j });
			}
		}
	}
	bfs();
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (check[i][j] > max)//더 큰값 찾으면
				max = check[i][j];
			if (map[i][j] == 0&&check[i][j]==-1)//안익은게 있을때
			{
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", max);
	return 0;
}
