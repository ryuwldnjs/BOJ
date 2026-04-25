#include <stdio.h>
#include <queue>
using namespace std;
bool visited[100005];
int dist[100005];
queue <int> q; 
int a,b,m,n, ans;

int pass(int x) //배열 이탈 
{
	if(x>=0 && x<=100000)
	return true;
	return false;
}
int main()
{
	scanf("%d %d %d %d", &a, &b, &n, &m);
	int dx[8] = {1,-1,a,-a,b,-b,a,b};
	
	q.push(n);
	visited[n] = true;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		if(p == m) //엌 도착
		{
			ans = dist[p];
			break;
		} 
		
		//1칸 +- / a칸+- / b칸+- / a칸 배 + /b칸 배 +    총 8가지 
		for(int i=0;i<8;i++)
		{
			
			if(i<6) //덧셈뺄셈
			{
				int tmp = p+dx[i];
				if(pass(tmp)&&!visited[tmp])
					{
					q.push(tmp), visited[tmp]=true;
					dist[tmp] = dist[p]+1;
					}
			} 
		 else //곱셈 
			{
				int tmp = p*dx[i];
				if(pass(tmp)&&!visited[tmp])
					{
					q.push(tmp), visited[tmp]=true;
					dist[tmp] = dist[p]+1;
					}
			}
			 
		}
		
	}
	
	printf("%d", ans);
	return 0;
}