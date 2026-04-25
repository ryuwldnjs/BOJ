#include <stdio.h>
#include <queue>

using namespace std;
int n, chon_1, chon_2, m;// 사람수, 비교대상 두명, 부모자식들 간의 관계수
int map[101][101]; //부모자식 맵
int visited[101];
int started;
int now, cnt;
struct point
{
	int obj; //조회할 사람
	int cnt; // 계산된 촌수
};

queue<point> q;//구조체 point 기반 큐q 선언
void BFS(int start)
{
	visited[start] = 1;
	q.push({ start, 0 });

	while (!q.empty()) //큐가 빌때 까지 반복
	{
		now = q.front().obj;
		cnt = q.front().cnt;
		q.pop();

		if (now == chon_2)
			printf("%d", cnt);
		else if (started && !visited[chon_2] && cnt == 0)
			printf("-1");



		started = 1;

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i] && map[now][i] == 1)
			{
				visited[i] = 1;
				q.push({ i, cnt + 1 });
			}
		}
	}

	if (!visited[chon_2])
		printf("-1");

}
int main()
{
	scanf("%d", &n);
	scanf("%d %d", &chon_1, &chon_2);
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = map[b][a] = 1;

	}

	BFS(chon_1);
	return 0;
}