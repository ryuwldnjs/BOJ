#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > map, tmp;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int visited[101][101];
int n,m,cnt, remained_cheese;
bool pass(int x, int y){ ///맵이탈 체크 
	if(0<=x&&x<n && 0<=y&&y<m)
		return true;
	return false;
}

void dfs(int x, int y){
	visited[x][y] = 1;
	
	if(map[x][y]){
		tmp[x][y] = 0;
		cnt++;
		return;
	}
	
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(pass(xx, yy) && !visited[xx][yy]){
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
			if(map[i][j]) remained_cheese++;
		}
	}
	tmp = map;//복사
	
	int time = 0;
	while(++time){
		cnt = 0; //이번에 사라질 치즈 개수 
		dfs(0,0);
		//dfs 돌리기
		 
		if(cnt == remained_cheese) break;
		//이번에 사라질 치즈개수와 남은 치즈개수가 같다면?? 
		
		remained_cheese -= cnt;
		map = tmp;
		for(int i=0;i<n;i++)
			fill(visited[i], visited[i]+m,0);
	}
	
	cout<<time<<'\n'<<cnt;
	return 0;
}