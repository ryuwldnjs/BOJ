#include <iostream>
using namespace std;
int n,m, answer;
char map[55][55];
bool visited[55][55];
bool pass(int x, int y){
	return 0<=x&&x<n && 0<=y&&y<m && !visited[x][y];
}
void dfs(int x, int y, char target){
	visited[x][y] = true;
	if(target == '|' && target == map[x+1][y] && pass(x+1,y)) 
		dfs(x+1,y,target);
	if(target == '-' && target == map[x][y+1] && pass(x,y+1)) 
		dfs(x,y+1,target);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]) continue;
			if(map[i][j] == '-') dfs(i,j,'-');
			else dfs(i,j,'|');
			answer++;
		}
	}
	cout<<answer;
	return 0;
}