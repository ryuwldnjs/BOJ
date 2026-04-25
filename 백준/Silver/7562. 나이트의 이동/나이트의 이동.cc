#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int map[305][305];
int visited[305][305];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
int t, l, a, b, c, d;
struct xy {
	int x;
	int y;
	int cnt;
};
queue <xy> q;

bool pass(int x, int y) //맵 이탈
{
	if (x >= 0 && y >= 0 && x < l && y < l)
		return true;
	return false;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		while (!q.empty())
			q.pop();
		memset(visited, 0, sizeof(map));
		scanf("%d", &l);
		scanf("%d %d", &a, &b);
		q.push({ a,b,0 });
		scanf("%d %d", &c, &d); //목적지


		while (!q.empty())
		{
			int xx = q.front().x;
			int yy = q.front().y;
			int cnt = q.front().cnt;
			q.pop();
			if (xx == c && yy == d)
			{
				printf("%d\n", cnt);
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				if (pass(xx+dx[i], yy+dy[i]) && visited[xx + dx[i]][yy + dy[i]] == 0)
				{
					q.push({ xx + dx[i], yy + dy[i], cnt+1 });
					visited[xx + dx[i]][yy + dy[i]] = 1;
				}
			}
		}
	}
	return 0;
}

