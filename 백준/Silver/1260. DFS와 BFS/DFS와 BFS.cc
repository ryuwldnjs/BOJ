#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
bool visited[1005], map[1005][1005];
int n,m,v,a,b;

void dfs(int now){
	visited[now]=true;
	cout << now<<" ";
	for(int i=1;i<=n;i++){
		if(map[now][i]&&!visited[i]){
			dfs(i);
		}
	}
}

void bfs(int start){
	q.push(start);
	visited[start]=true;
	while(!q.empty()){
		int now = q.front();
		cout << now<<" ";
		for(int i=1;i<=n;i++){
			if(map[now][i]&&!visited[i]){
				q.push(i);
				visited[i]=true;
			}
		}
		q.pop();
		
	}
}
int main(){
	cin >>n>>m>>v;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		map[a][b]=map[b][a]=true;
	}
	dfs(v);
	fill(visited, visited+1005, false);
	cout <<"\n";
	bfs(v);
	
	return 0;
}