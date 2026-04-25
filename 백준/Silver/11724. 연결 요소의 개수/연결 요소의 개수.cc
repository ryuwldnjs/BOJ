#include <stdio.h>
int map[1010][1010];
int visited[1010];
int M, N;
int cnt;
void solve(int a)
{
	//map[a][b] = map[b][a] = 0; //이미 지나온 경로는 삭제
	visited[a] = 1; //방문
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0 && map[a][i] == 1) //방문하지 않고, 연결됐을 때
			solve(i);
	}
}
int main()
{
	int u, v;
	scanf("%d %d", &N, &M); //정점개수, 간선개수
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &u, &v);
		map[u][v] = 1, map[v][u] = 1;//무방향
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0) //방문 안했을때
			solve(i), cnt++;
	}
	printf("%d", cnt);
	return 0;
}