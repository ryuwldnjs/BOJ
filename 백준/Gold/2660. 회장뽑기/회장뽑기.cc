#include <stdio.h>
#include <algorithm>
#define INF 987654321
using namespace std;
int n;
int dis[55][55];
int a, b, score, cnt;
int ans[55];
int sum[55];//각 사람 점수
int maxx[55];
	int main()
{
	
	scanf("%d", &n);
	
	for(int i =1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i != j)
		dis[i][j] = INF;
	}
	while(true)
	{
		scanf("%d %d", &a, &b);
		if(a == -1 || b == -1)
		break;
		
		dis[a][b]=  dis[b][a] = 1;
		
	}
	//플로이드
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j]> dis[i][k] + dis[k][j])
				dis[i][j] = dis[i][k] + dis[k][j];
			}
	int min=INF;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dis[i][j]>maxx[i])
			maxx[i] = dis[i][j];
		}
		if(maxx[i]<min)
		min = maxx[i];
		
	}	
			
	for(int i=1;i<=n;i++) 
	{
		if(maxx[i] == min)
		cnt++, ans[cnt]=i;
	}
	
	printf("%d %d\n", min, cnt);
	
	for(int i=1;i<=cnt;i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}