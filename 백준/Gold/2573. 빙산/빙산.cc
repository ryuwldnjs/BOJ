#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int n, m;
int dp[1005];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int map[305][305]; //빙산 
int tmp[305][305];  //빙산 녹이기 tmp
int visited[305][305];
int year;

vector <pair<int, int> > vec;

void melt(int x, int y)
{
	for(int i=0;i<4;i++)
	{
		if(map[x+dx[i]][y+dy[i]] <= 0) //주변에 물 
		tmp[x][y]--;
	}
}

void dfs(int x, int y) 
{
    melt(x,y);
	visited[x][y] = 1;
	for(int i=0;i<4;i++)
	{
		if(map[x+dx[i]][y+dy[i]] > 0 && visited[x+dx[i]][y+dy[i]] == 0) //엌 빙산 발견 
		dfs(x+dx[i], y+dy[i]);
	}
}

void copy()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			map[i][j] = tmp[i][j];
		}
	}
 } 
int main()
{
	
	scanf("%d %d", &n, &m);
	
	for(int i =1;i<=n;i++)
	{
		for(int j=1; j<=m;j++)
		{
			scanf("%d", &map[i][j]);
			tmp[i][j] = map[i][j];
			if(map[i][j]>0) vec.push_back({i,j});
		}
	}
	
	
	
	while(true) //한번 돌면 1년 
	{

		int cnt=0;
		memset(visited, 0, sizeof(visited));// 초기화 
			
			
		for(int i=0;i<vec.size();i++){
			int x = vec[i].first;
			int y = vec[i].second;
			
			if(!visited[x][y] && map[x][y]>0){
				dfs(x,y);
				cnt++;
			}
		}
		
		copy();//맵 업데이트 
		
		if(cnt >=2) //두개 이상 분리 돼있으면
		{
			break;
		 } 

		
		 if(cnt==0){
		 	printf("0");
		 	return 0;
		 }
		 year++;
	}
	
	printf("%d", year);
	return 0;
} 