#include <stdio.h>
#include <algorithm>
#define INF 999
using namespace std;
int n, m, u,v,b;
int k, s, e;
int dist[255][255];
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				dist[i][j] = INF;

	for (int i = 1; i <=m; i++)
	{
		scanf("%d %d %d", &u, &v, &b);
		dist[u][v] = 0;
		dist[v][u] = (b == 0 ? 1 : 0);
	}


	//플로이드
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &s, &e);
		printf("%d\n", dist[s][e]);
	}
	return 0;
}