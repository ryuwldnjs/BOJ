#include <stdio.h>
int arr[55][55];
int M, N, K;//가로 세로 배추갯수
int x, y;//배추 좌표
int cnt;
void BFS(int a, int b)
{
	arr[a][b] = 0;
	if (arr[a + 1][b] == 1)
		BFS(a + 1, b);
	if (arr[a - 1][b] == 1)
		BFS(a - 1, b);
	if (arr[a][b + 1] == 1)
		BFS(a, b + 1);
	if (arr[a][b - 1] == 1)
		BFS(a, b - 1);
}
int main()
{
	int T; //테스트 케이스
	scanf("%d", &T);


	for (int i = 0; i < T; i++)
	{
		cnt = 0;
		scanf("%d %d %d", &M, &N, &K);
		for (int a = 0; a <= M+1; a++) //가장자리 -1처리
		{
			for (int b = 0; b <= N+1; b++)
			{
				if (a == 0 || a == M + 1 || b == 0 || b + N + 1)
					arr[a][b] = -1;
			}
		}
		for (int j = 0; j < K; j++) //배추 위치 저장
		{
			scanf("%d %d", &x, &y);
			arr[x+1][y+1] = 1;
		}

		for (int a = 1; a <= M; a++)
		{
			for (int b = 1; b <= N; b++)
			{
				if (arr[a][b] == 1)
				{
					cnt++;
					BFS(a, b);
				}
			}
		}

		printf("%d\n", cnt);
	}
	return 0;
}