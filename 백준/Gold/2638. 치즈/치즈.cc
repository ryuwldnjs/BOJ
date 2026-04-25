#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > map, tmp;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int visited[101][101];//방문 횟수
int n,m,cnt, total_cheese;
bool pass(int x, int y){ ///맵이탈 체크 
	if(0<=x&&x<n && 0<=y&&y<m)
		return true;
	return false;
}

void dfs(int x, int y){
	visited[x][y]++;
	
	if(map[x][y]){ //치즈를 두번째로 방문시 
		if(visited[x][y]==1) return;//첫번째 방문시 치즈에 영향없이 종료 
		
		//두번째 방문시 치즈를 살살 녹여줍니다~ 
		tmp[x][y] = 0; 
		cnt++;
		return;
	}
	
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(pass(xx, yy) && (!visited[xx][yy] || map[xx][yy]==1&&visited[xx][yy]<2)){
			dfs(xx, yy);
		}
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	map.resize(101);
	for(int i=0;i<101;i++) map[i].resize(101);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j]) total_cheese++;
		}
	}
	tmp = map;//복사
	
	int time = 0;
	while(++time){
		cnt = 0; //이번에 사라질 치즈 개수 
		dfs(0,0);
		//dfs 돌리기
		
		total_cheese -= cnt;
		if(total_cheese==0) break;//모든 치즈가 다 녹았으면 종료ㅗ
		 
		map = tmp;
		for(int i=0;i<n;i++)
			fill(visited[i], visited[i]+m,0);
	}
	
	cout<<time;
	return 0;
}