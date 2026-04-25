#include <stdio.h>
#include <algorithm>
using namespace std;
#include <queue>
int visited[100005];
struct stats {
	int x;
	int dis;
};
int ans;
queue <stats> q;
int main()
{
	int n,k;

	scanf("%d %d", &n, &k);

	q.push({ n,0 });


	while (!q.empty())
	{
		int x = q.front().x;
		int dis = q.front().dis;
		visited[x] = 1;
		q.pop();
		if (x == k)//어 찾음
		{
			ans = dis;
			break;
		}
		if (x >= 1 && visited[x-1]==0)
			q.push({ x - 1, dis + 1 });
		if (x < 100000 && visited[x+1]==0)
			q.push({ x + 1,dis + 1 });
		if (x <= 50000 && visited[2*x]==0)
			q.push({ 2 * x, dis + 1 });

	}

	printf("%d", ans);
	return 0;
}