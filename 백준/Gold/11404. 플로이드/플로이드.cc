#include <stdio.h>
#include <algorithm>

#define INF 987654321
using namespace std;
int dis[105][105];
int main()
{
	int n, m;
	int a, b, cost;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				dis[i][j] = 0;
			else
				dis[i][j] = INF;
		}
	}


	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &cost);
		if(dis[a][b]>cost)
			dis[a][b] = cost;
	}
	//플로이드
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dis[i][j] == INF) //갈수없을때
				printf("0 ");
			else
				printf("%d ", dis[i][j]);
		}
		printf("\n");
	}
	return 0;
}

