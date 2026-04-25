#include <stdio.h>
#include <algorithm>
using namespace std;

int c, r, k;
int ans, cnt;
int arr[1005][1005];
int dx[4] = { 0,1,0,-1 }; //상 우 하 좌
int dy[4] = { 1,0,-1,0 };
bool check(int a, int b)
{
	if (a >= 1 && b >= 1 && a <= c && b <= r)
		return true;
	return false;
}
int main()
{
	scanf("%d %d %d", &c, &r, &k);

	if (c*r < k) //좌석이 없을때
	{
		printf("0");
		return 0;
	}
	int x = 1, y =0;
	for (int i = 1; i <= c*r; i++)
	{

		x += dx[cnt], y += dy[cnt];
		arr[x][y] = 1;

		if (arr[x + dx[cnt]][y + dy[cnt]] || !check(x+dx[cnt], y+dy[cnt])) //벽 닿일때
			cnt++, cnt %= 4;

		if (i == k)
		{
			printf("%d %d", x, y);
			return 0;
		}
	}
	return 0;
}

