#include <iostream>
using namespace std;
int n,m,map[105][105];
int jump;
bool visited[105][105];
bool pass(int y, int x){
	return 0<=y&&y<n 
		&& 0<=x&&x<m 
		&& map[y][x] == map[0][0];
}
int dfs(int y, int x){
	visited[y][x] = true;
	bool isAnswer = false;
	if(y==n-1 && x==m-1) return true;
	
	for(int dy=-jump;dy<=jump;dy++){
		for(int dx=-jump+abs(dy); dx<=jump-abs(dy);dx++){
			int xx = x + dx;
			int yy = y + dy;
			if(pass(yy,xx) && !visited[yy][xx]){
				isAnswer |= dfs(yy,xx); 
			}
		}

	}
	return isAnswer;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	cin>>jump;
	cout<<(dfs(0,0) ? "ALIVE" : "DEAD");
	return 0;
}