#include <iostream>
using namespace std;
int n,m;
int map[350][350];
bool visited[350][350], answer;
bool pass(int x, int y){
	return 0<=x&&x<m && 0<=y&&y<n && map[x][y]==1;
} 
void dfs(int x, int y){
	visited[x][y] = true;
	if(x == m-1 && y == n-1){
		answer = true;
		return;
	}
	if(pass(x+1, y) && !visited[x+1][y]) dfs(x+1, y);
	if(pass(x, y+1) && !visited[x][y+1]) dfs(x, y+1);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	
	dfs(0,0);
	
	cout<<(answer ? "Yes" : "No");
	return 0;
}