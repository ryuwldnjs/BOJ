#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
vector <int> adj[10005];
bool visited[10005];
int result[10005];
void dfs(int n)
{
	visited[n] =true;
	for(int i=0;i<adj[n].size();i++)
	{
		int next = adj[n][i];
		if(visited[next] ==0)
		{
			dfs(next);
			result[next]++;
		}
	}
}
int main(){
	int n, m;
	int a,b;
	scanf("%d %d", &n, &m);
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d", &a, &b); // a가 b를 신뢰 함 
		adj[a].push_back(b);
	}
	
	for(int i=1;i<=n;i++)
	{
	memset(visited, false, sizeof(visited));
	dfs(i); 	 
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
		ans = max(ans, result[i]);
	
	for(int i =1;i<=n;i++)
	{
		if(result[i]==ans)
		printf("%d ", i);
	}
	return 0;
}