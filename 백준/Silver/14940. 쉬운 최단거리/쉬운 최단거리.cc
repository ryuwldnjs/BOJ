#include <iostream>
#include <queue>
using namespace std;
using pii=pair<int,int>;
int visited[1005][1005];
int map[1005][1005];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int n,m;
queue<pii> q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
			if(map[i][j] == 2){
				q.push({i, j});
			}
		}
	}
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		for(int i=0;i<4;i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if(map[xx][yy] == 1 && !visited[xx][yy]){
				visited[xx][yy] = visited[x][y] + 1;
				q.push({xx, yy});
			}
		}
	}
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int dist = map[i][j]!=1 || visited[i][j] ? visited[i][j] : -1;
			cout<<dist<<' ';
		}
		cout<<'\n';
	}
	return 0;
}