#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, dis[105][105]; //거리 
int main()
{
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d", &dis[i][j]);
			if(dis[i][j]==0) //연결x일때
			dis[i][j]=INF; 
		}
	}
	
	
	//플로이드 구현
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		dis[i][j]= min(dis[i][j], dis[i][k]+dis[k][j]);
	} 
	
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
	{
		if(dis[i][j] != INF) //최단경로가 존재할때
		printf("1 ");
		else
		printf("0 "); 
	}
	printf("\n");
	}
	return 0;
}