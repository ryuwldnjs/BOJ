#include <bits/stdc++.h>
using namespace std;
char field[105][105];
bool visited[105][105];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int m,n,W,B;
bool pass(int x, int y){
	return 0 <= x&&x < m && 0 <= y&&y < n && !visited[x][y];
}
int dfs(int x, int y){
	int cnt = 1;
	visited[x][y] = true;
	
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(pass(xx,yy) && field[x][y] == field[xx][yy]) cnt += dfs(xx,yy); 
	}
	return cnt;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>field[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int cnt = 0;
			if(!visited[i][j]) cnt = dfs(i,j);
			
			if(field[i][j] == 'W') W += cnt*cnt;
			else B += cnt*cnt;
		}
	}
	
	cout<<W<<' '<<B;
	return 0;
}