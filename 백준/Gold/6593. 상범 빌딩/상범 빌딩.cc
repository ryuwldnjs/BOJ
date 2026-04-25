#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
struct stats{
	int x;
	int y;
	int z;
	int dist;
};
int L,R,C;
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
char map[35][35][35];
bool visited[35][35][35];
int a,b,c,ans; //출구 좌표 
queue <stats> q;
bool pass(int x, int y, int z)
{
	if(1<=x&&x<=C && 1<=y&&y<=R && 1<=z&&z<=L)
	return true;
	return false;
}
int main()
{
	while(true)
	{
		//초기화 
		memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
		while(!q.empty())
			q.pop();
		ans=0;
		
		scanf("%d %d %d", &L, &R, &C);
		if(L==0&&R==0&&C==0)
		break;
		
		for(int k=1;k<=L;k++)
		{
			for(int i=1;i<=R;i++)
			{
				for(int j=1;j<=C;j++)
				{
					scanf(" %c", &map[j][i][k]);
					if(map[j][i][k]=='S')
					q.push({j,i,k, 0}),visited[j][i][k]=1;
					if(map[j][i][k]=='E')//도착점 
					a=j, b=i, c=k; 
				}
			}
		}
		
		
		while(!q.empty())
		{
			int x=q.front().x;
			int y=q.front().y;
			int z=q.front().z;
			int dist=q.front().dist;
			q.pop();
			
			if(x==a&&y==b&&z==c) //엌 도착 
			{
				ans=dist;
				break;
			}
			
			for(int i=0;i<6;i++)
			{
				int xx=x+dx[i];
				int yy=y+dy[i];
				int zz=z+dz[i];
				
				if(pass(xx,yy,zz) && map[xx][yy][zz]!='#'&&!visited[xx][yy][zz])
				q.push({xx,yy,zz,dist+1}), visited[xx][yy][zz]=1;
			}
		}
		
		
		if(ans ==0)
		printf("Trapped!\n");
		else
		printf("Escaped in %d minute(s).\n", ans);		
	}
	return 0;
}