#include <stdio.h>
//#include <algorithm>
#define INF 987654321
using namespace std;
int n, c;
int dis[405][405];
int a, b;
int s;
int main()
{
	scanf("%d %d", &n, &c);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			dis[i][j] = INF;
		}
	}
	
	for(int i=1; i<=c;i++)
	{
		scanf("%d %d", &a, &b);
		dis[a][b] = 1;
	}
	
	
	//플로이드
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	 } 
	 
	 scanf("%d", &s);
	 
	 for(int i=0;i<s;i++)
	 {
	 	scanf("%d %d", &a, &b);
	 	
	 	if(dis[a][b] <INF) //답 존재O
	 	{ 
	 		printf("-1\n");
	 		continue;
	 		
		 }
		 else if(dis[b][a] < INF)
		 {
		 	printf("1\n");
		 	continue;
		 }
		 else
		 
		 {
		 	printf("0\n");
		 	continue;
		 }
	 }
	return 0;
}