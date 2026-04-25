#include <stdio.h>
#include <algorithm>
#define INF 987654321
using namespace std;
int w[105][105]; //무게
int main()
{
	int n, m;
	int a, b;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				w[i][j] = 0;
			else
				w[i][j] = INF;
		}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		w[a][b] = 1;
	}
	//플로이드
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				if (w[i][j] > w[i][k] + w[k][j])
					w[i][j] = w[i][k] + w[k][j];
			}

	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (w[i][j] < INF) //대소비교는 양쪽으로 가능하므로
				w[j][i] = 1;
			if (w[j][i] < INF)
				w[i][j] = 1;

			if (w[i][j] >= INF) //i가 j와 비교할수없을때
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}

