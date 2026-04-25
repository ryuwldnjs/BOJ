#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
int a, b, c, d;
int ans;
int map[100005][4];
//a통 빈거, a통 꽉찬거
//b통 빈거, b통 꽉찬거 ㅇㅋ?

struct stats {
	int x; //현재 물통 상태
	int y; //
};
queue <stats> q;

int dis(int x, int y)
{
	if (x == 0)
		return map[y][0];
	if (x == a)
		return map[y][1];
	if (y == 0)
		return map[x][2];
	if (y == b)
		return map[x][3];
	else
		return -1;
}

void push(int x, int y, int d)
{
	if (x == 0) {
		if (map[y][0] == -1) {
			map[y][0] = d;
			q.push({x,y});
		}
	}
	else if (x == a) {
		if (map[y][1] == -1) {
			map[y][1] = d;
			q.push({ x,y });
		}
	}
	else if (y == 0) {
		if (map[x][2] == -1) {
			map[x][2] = d;
			q.push({ x,y });
		}
	}
	else if (y == b) {
		if (map[x][3] == -1) {
			map[x][3] = d;
			q.push({ x,y });
		}
	}

}
int main()
{
	scanf("%d %d %d %d", &a, &b, &c, &d);

	for (int i = 0; i <= b; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			map[i][j] = -1;
		}
	}
	if (c != 0 && d != 0 && c != a && d != b)
	{
		printf("-1");
		return 0;
	}
	push(0, 0, 0);
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		int d = dis(x, y);

		push(x, 0, d + 1);
		push(x, b, d + 1);
		push(0, y, d + 1);
		push(a, y, d + 1);
		
		int tmp = min(x, b - y);
		push(x - tmp, y + tmp, d + 1); //a to b
		tmp = min(a - x, y);
		push(x + tmp, y - tmp, d+1); //b to a

	}

	printf("%d", dis(c,d));
	return 0;
}