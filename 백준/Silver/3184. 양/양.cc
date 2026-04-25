#include <stdio.h>
using namespace std;
int cc;
int arr[255][255];
int visited[255][255];
int sheep, wolf;
int s,w; //한 구역에서 
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int r,c;
bool pass(int a, int b)
{
	if(a>=1&& b>=1 && a<=r && b <=c && arr[a][b] !=1)
	return true;
	return false;
}
void dfs(int a, int b)
{
//	printf("zz ");
	visited[a][b] =1;
	if(arr[a][b] == 22) //양
	 s++;
	else if(arr[a][b]==33) //늑대
	 w++;
	 
	for(int i=0;i<4;i++)
	{
		int xx = a+dx[i];
		int yy = b+dy[i];
		
		if(visited[xx][yy]==0 && pass(xx, yy))
		{
		dfs(xx, yy);		
		}
	}
	
}
int main()
{
	
	scanf("%d %d", &r, &c);
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			scanf(" %c", &cc);
			if(cc=='.')
			arr[i][j]=0;
			else if(cc=='#')
			arr[i][j] = 1;
			else if(cc=='o'){
				arr[i][j] = 22;
				sheep++;	
			}
			else if(cc== 'v'){
				arr[i][j]=33;
				wolf++;
			}
			
		}
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			s=0,w=0;//양 늑대 
			if(visited[i][j] ==0 && pass(i,j))
			{
				dfs(i,j);
				if(s>w) wolf -=w;
				else sheep -= s; 
			}
		//	printf("%d %d    ", w,s);	
		}
	}
	
	
printf("%d %d", sheep, wolf);
	return 0;
}