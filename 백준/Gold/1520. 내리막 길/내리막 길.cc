#include <iostream>
using namespace std;
int map[505][505];
int dp[505][505];
// dp[i][j] : map[i][j]에서 도착점에 갈수있는 경우의 수 
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int m,n;

//맵이탈 체크 
bool pass(int x, int y){
	if(0<=x&&x<m && 0<=y&&y<n)
		return true;
	return false;
}

// DFS + DP
int dfs(int x, int y){
	int &ret = dp[x][y];
	
	//기저사례 
	if(x==m-1 && y==n-1)
		return 1;
		
	if(ret != -1) return ret;
	ret = 0;
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if(pass(xx, yy) && map[x][y] > map[xx][yy]){
			ret += dfs(xx, yy);
		}
	}
	return ret; 
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	 
	cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			dp[i][j] = -1;
		}
		
	cout<<dfs(0, 0);
	return 0;
}