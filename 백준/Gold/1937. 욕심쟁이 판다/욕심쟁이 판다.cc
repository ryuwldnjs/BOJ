#include <iostream>
using namespace std;
int map[505][505];
int dp[505][505];
//dp[i][j] : map[i][j]에서 시작시 최대한 살수 있는 일수 
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int n;

//맵이탈 체크 
bool pass(int x, int y){
	if(0<=x&&x<n && 0<=y&&y<n)
		return true;
	return false;
}

//DFS + DP
int dfs(int x, int y){
	int &ret = dp[x][y];
	
	if(ret != -1) return ret;
	ret = 1;
	
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if(pass(xx,yy) && map[x][y] < map[xx][yy]){
			ret = max(ret, dfs(xx,yy) + 1);
		}
	}
	
	return ret;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int MAX=0;
	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			dp[i][j] = -1;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			MAX = max(MAX, dfs(i,j));
		}
	}
	cout<<MAX;
	return 0;
}