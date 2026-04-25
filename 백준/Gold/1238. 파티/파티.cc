#include <stdio.h>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, m, x;
int dis[1005][1005];
int main()
{
	int a, b, t;
	scanf("%d %d %d", &n, &m, &x);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				dis[i][j] = 0;
			else
				dis[i][j] = INF;
		}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &t);
		dis[a][b] = t;
	}



	//플로이드
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
    
	int max=0;
	for (int i = 1; i <= n; i++)
		if (dis[i][x] + dis[x][i] > max)
			max = dis[i][x] + dis[x][i];
    
	printf("%d", max);
	return 0;
}

