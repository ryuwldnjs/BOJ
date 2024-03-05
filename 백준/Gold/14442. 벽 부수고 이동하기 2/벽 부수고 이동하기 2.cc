#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Info{
	int x;
	int y;
	int cost;
	int smash;
};
int n,m,k;
int map[1005][1005];
int visited[1005][1005][11];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool pass(int x, int y){
	return 0<=x&&x<n && 0<=y&&y<m;
}
int bfs(){
	queue<Info> q;
	
	q.push({0,0,1,0});
	visited[0][0][0];
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int cost = q.front().cost;
		int smash = q.front().smash;
		q.pop();
		
		if(x==n-1 && y==m-1){
			cout<<cost;
			return 1;
		}
		
		for(int i=0;i<4;i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			//빈 공간 
			if(pass(xx, yy) && map[xx][yy]==0 && !visited[xx][yy][smash]){
				visited[xx][yy][smash] = true;
				q.push({xx,yy,cost+1,smash});
			}
			//벽 
			if(pass(xx,yy) && map[xx][yy]==1 && smash < k && !visited[xx][yy][smash+1]){
				visited[xx][yy][smash+1] = true;
				q.push({xx,yy,cost+1,smash+1});
			}
		}
	}
	return 0;
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c;
			cin>>c;
			map[i][j] = c - '0';
		}
	}
	
	if(bfs() == 0) cout<<-1;
	return 0;
}