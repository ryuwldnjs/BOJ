#include <iostream>
#include <queue>
using namespace std;
struct stats{
	int x;
	int y;
	int cost;
	int smash;
};
queue<stats> q;
int map[1005][1005];
bool visited[1005][1005][2];//0은 벽 안뚫었을때 
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int n,m;
char c;
bool pass(int x, int y){
	if(1<=x&&x<=n && 1<=y&&y<=m)
		return true;
	return false;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			map[i][j] = c - '0';
		}
	}
	
	q.push({1,1,1,0});
	
	while(!q.empty()){
		stats now = q.front();
		//printf("%d, %d: %d,%d\n", now.x, now.y, now.cost, now.smash); 
		q.pop();
		
		if(now.x == n && now.y == m){
			cout<<now.cost;
			return 0;
		}
		
		for(int i=0;i<4;i++){
			int xx = now.x + dx[i];
			int yy = now.y + dy[i];
			int cost = now.cost;
			int smash = now.smash;
			
			if(pass(xx, yy)){
				//벽이 있고, 벽을 부술수 있을때 
				if(map[xx][yy] == 1 && smash == 0 && !visited[xx][yy][0]){
					q.push({xx, yy, cost+1, smash+1});
					visited[xx][yy][0] = true;
				}
				//이전 방문에서 smash 사용유무에 따라 방문체크 분리 
				else if(map[xx][yy] == 0 && !visited[xx][yy][smash]){
					q.push({xx, yy, cost+1, smash});
					visited[xx][yy][smash] = true;
				}
			}
		}
		
	}
	
	cout<<-1;
	return 0;
}