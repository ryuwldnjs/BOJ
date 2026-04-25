#include <stdio.h>
#include <algorithm>
using namespace std;
int n, map[30][30];
int danjisu, danji[630];

void BFS(int a, int b)
{
	map[a][b] = 0;
	danji[danjisu]++;
//주변에 있는 1로 이동
	if (map[a-1][b] == 1)
		BFS(a-1, b);
	if (map[a+1][b] == 1)
		BFS(a+1, b);
	if (map[a][b-1] == 1)
		BFS(a, b-1);
	if (map[a][b+1] == 1)
		BFS(a, b+1);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n+1; i++) //테두리 만들기
		for (int j = 0; j <= n+1; j++)
			map[i][j] = -1;
	for (int i = 1; i <= n; i++) //데이터값 넣기
		for (int j = 1; j <= n; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 1; i <= n; i++) //탐색
		for (int j = 1; j<= n; j++)
			if (map[i][j] == 1)//아파트 발견!
			{
				danjisu++; //단지 수 증가
				BFS(i, j); //BFS로 주변 아파트를 모두 0으로
			}
	printf("%d\n", danjisu);
	sort(danji + 1, danji + danjisu + 1);
	for (int i = 1; i <= danjisu; i++)
		printf("%d\n", danji[i]);
	return 0;
}