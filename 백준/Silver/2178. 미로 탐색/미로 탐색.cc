#include <stdio.h>
#include <queue>
using namespace std;
int m, n;
int map[110][110];
int check[110][110];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1, };
struct xy { int x; int y; };
queue <xy> q;
void bfs()
{

	q.push({1,1});//1,1부터 시작
	check[1][1] = 1;
	while (!q.empty())//큐가 빌때까지
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++)
			if (map[x + dx[i]][y + dy[i]] == 1 && check[x + dx[i]][y + dy[i]] == 1)
			{
				q.push({ x + dx[i],y + dy[i] });
				check[x + dx[i]][y + dy[i]] = check[x][y] + 1;
			}
	}
}
int main()
{

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			check[i][j] = -1;//지정된 구역이 맞는지
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1)//지나갈수 있는 칸일때
				check[i][j] = 1;
			
		}
	}
	bfs();
	printf("%d", check[n][m]);
	return 0;
}
