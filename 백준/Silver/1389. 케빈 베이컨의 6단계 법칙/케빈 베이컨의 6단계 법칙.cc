#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 987654321
int a,b;
int n, m, dis[105][105]; //거리 
int sum[105]; //케빈 베이컨의 수 저장 
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++) //초기 설정 
	for(int j=1;j<=n;j++)
	i==j ? dis[i][j]=0 : dis[i][j]=INF;
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d", &a, &b);
		dis[a][b] = 1, dis[b][a]=1;
	}
	
	
	//플로이드 구현
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		dis[i][j]= min(dis[i][j], dis[i][k]+dis[k][j]);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum[i] += dis[i][j]; //케빈 베이컨 
		}
	} 
	
	
	int min=98765432, ans;
	for(int i=1;i<=n;i++)
	if(sum[i]<min) //갱신 
	min = sum[i], ans=i;
	
	printf("%d", ans);
	return 0;
}