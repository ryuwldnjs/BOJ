#include <stdio.h>
#include <algorithm>
using namespace std;
int r,c;//세로 가로 
char map[255][255];
int wolf,sheep;
int wolf_cnt,sheep_cnt;
int visited[255][255];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool pass(int a,int b)
{
	if(a>=1&&b>=1&&a<=r&&b<=c)
	return true;
	return false;
}

int dfs(int x, int y)
{
	visited[x][y]=1;
	if(map[x][y]=='v')
	wolf_cnt++;
	else if(map[x][y]=='k')
	sheep_cnt++;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		
		if(pass(xx,yy) && map[xx][yy] != '#' &&!visited[xx][yy])
		dfs(xx,yy);
	}
}
int main()
{
	scanf("%d %d", &r, &c);
	
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			scanf(" %c", &map[i][j]);
			if(map[i][j]=='v')
			wolf++;
			if(map[i][j]=='k')
			sheep++;
		}
	 } //input
	 
	 for(int i=1;i<=r;i++)
	 {
	 	for(int j=1;j<=c;j++)
	 	{
	 		if(!visited[i][j]&&map[i][j] != '#')
	 		{
	 			wolf_cnt=0;
	 			sheep_cnt=0;
	 			dfs(i,j);
	 			if(wolf_cnt>=sheep_cnt)//늑대가 나타났다!
				 sheep-=sheep_cnt; 
				 else
				 wolf-=wolf_cnt;
			 }
		 }
	 }
	 
	 printf("%d %d", sheep, wolf);
	return 0;
}