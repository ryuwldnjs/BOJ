#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;//컴퓨터수, 컴퓨터쌍 수
int a, b;
int map[105][105], visited[105], cnt;
void dfs(int a)
{
	visited[a] = 1;//a방문
	cnt++;
	for (int i = 1; i <=n; i++)
	{
		if (map[a][i] == 1 && visited[i] == 0)//n에서 i로 가는 길이 있고, 방문x일경우
			dfs(i);
	}
}
int main()
{
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &a, &b);
		map[a][b] = map[b][a] = 1;//간선 연결
	}
	dfs(1);
	printf("%d", cnt-1);
	return 0;
}

