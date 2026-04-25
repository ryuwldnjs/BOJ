#include <stdio.h>
#include <algorithm>
using namespace std;

int dx[4] = { 1,-1,0,0 }; //4방향
int dy[4] = { 0,0,1,-1 };

int m, n, k;
int x1, x2, y2; //왼쪽아래 오른쪽 위 좌표
int y_1; // y1쓰면 오류남 왜그런진 모름
int map[105][105];
int cnt;
int S[105]; //각 넓이 

void dfs(int y, int x)
{
	map[y][x] = 1; //cnt번째 영역
	S[cnt]++;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m) //배열에서 넘어설때
			continue;
		if (map[yy][xx] == 0)//아직 방문 안했을때
			dfs(yy, xx);
	}
}
int main()
{
	scanf("%d %d %d", &m, &n, &k); // y x 사각형 개수
	for (int i = 0; i < k; i++) 
	{
		scanf("%d %d %d %d", &x1, &y_1, &x2, &y2);
		for (int i = x1; i < x2; i++)
			for (int j = y_1; j < y2; j++)
				map[j][i] = 1; //x,y값 넣을때 주의
	} // 여기까지 입력부분

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0) //빈 영역 찾음
				dfs(i, j),cnt++;
		}

	sort(S, S + cnt);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d ", S[i]);
	return 0;
}

