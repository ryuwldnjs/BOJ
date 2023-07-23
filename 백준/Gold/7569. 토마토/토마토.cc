#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int m,n,h;
int ans;
struct stats{
	int x;
	int y;
	int h;
};
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
queue <stats> q;
bool pass(int x, int y, int z)
{
	if(1<=x&&x<=m && 1<=y&&y<=n && 1<=z&&z<=h)
	return true;
	return false;
}
int map[105][105][105];
int main()
{
	scanf("%d %d %d", &m, &n, &h);
	for(int k=1;k<=h;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d", &map[j][i][k]);
				if(map[j][i][k]==1)
				q.push({j,i,k});
			}
		}
	}
	
	while(!q.empty())
	{
		int x=q.front().x;
		int y=q.front().y;
		int z=q.front().h;
		q.pop();		
		
		for(int i=0;i<6;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			int zz=z+dz[i];
			
			if(pass(xx,yy,zz) && map[xx][yy][zz] ==0)
			{
				q.push({xx,yy,zz}), map[xx][yy][zz]=map[x][y][z]+1;

			}
		}
	}
	
	for(int k=1;k<=h;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(map[j][i][k]==0) //안익은거 존재
				{
					printf("-1");
					return 0;
				 } 
 				ans = max(ans, map[j][i][k]);
			}
		}
	}
	
	printf("%d", ans-1);
	return 0;
}