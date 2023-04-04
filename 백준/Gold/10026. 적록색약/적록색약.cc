#include <stdio.h>
int map[110][110];
int map_blind[110][110];
int n, cnt, cnt_blind;
char c;

void solve(int a, int b, int c) //x, y좌표, 색깔
{
	map[a][b] = 0;
	if (map[a - 1][b] == c)
		solve(a - 1, b, c);
	if (map[a + 1][b] == c)
		solve(a + 1, b, c);
	if (map[a][b - 1] == c)
		solve(a, b-1, c);
	if (map[a][b+1] == c)
		solve(a, b+1, c);
}
void solve_blind(int a, int b, int c)
{
	map_blind[a][b] = 0;
	if (map_blind[a - 1][b] == c)
		solve_blind(a - 1, b, c);
	if (map_blind[a + 1][b] == c)
		solve_blind(a + 1, b, c);
	if (map_blind[a][b - 1] == c)
		solve_blind(a, b - 1, c);
	if (map_blind[a][b + 1] == c)
		solve_blind(a, b + 1, c);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf(" %c", &c);
			if (c == 'R')
			{
				map[i][j] = 1;
				map_blind[i][j] = 1;
			}
			else if (c == 'G')
			{
				map[i][j] = 2;
				map_blind[i][j] = 1;
			}
			else if (c == 'B')
			{
				map[i][j] = 3;
				map_blind[i][j] = 3;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(map[i][j] != 0) //색깔이 있을때
			{
				solve(i, j, map[i][j]);
				cnt++;
			}
			if (map_blind[i][j] != 0) //색깔이 있을때
			{
				solve_blind(i, j, map_blind[i][j]);
				cnt_blind++;
			}
		}
	}

	printf("%d %d", cnt, cnt_blind);
	return 0;
}