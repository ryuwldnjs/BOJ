#include <stdio.h>
#include <queue>
//#include <algorithm>
using namespace std;
int parent[3050];
typedef struct{
	int x;
	int y;
	int r;
} info;

info point[5050];
bool isadjcent(info a, info b) //서로 접하고 있는지
{
	if ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) <= (a.r + b.r)*(a.r + b.r)) //두점 사이 거리< 반지름 합
		return true; //접하고 있음
	else
		return false;
}
int find(int x) //첫 부모 찾기
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void unions(int x, int y) //유니온
{
	x = find(x);
	y = find(y);

	parent[x] = y; //x의 제일 첫부모는 y의 제일 첫부모

}
int main()
{
	int t,n, ans;//테스트케이스
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		ans = n;
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
			scanf("%d %d %d", &point[i].x, &point[i].y, &point[i].r);
		}

		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <=i-1; j++)
			{
				if (isadjcent(point[i], point[j]) && find(i) != find(j))//접해있고, 같은그룹이 아닐때
					unions(i, j), ans--;
			}
		}
		printf("%d\n", ans);

	}

	return 0;
}

