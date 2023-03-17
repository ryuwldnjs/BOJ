#include <iostream>
using namespace std;

int map[105][105];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n,m,k, demand;
bool pass(int x, int y){
	if(0<=x&&x<n && 0<=y&&y<n)
		return true;
	return false;
}


int dfs(int x, int y){
	int cnt = 1;
	map[x][y] = 1;
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if(pass(xx,yy) && map[xx][yy] == 0){ //빈칸 
			cnt += dfs(xx,yy);
		}
	}
	return cnt;
}

int main(){
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j] == 0){ //한 구역당 필요한 포자 수 계산 
				demand += (dfs(i,j) + k-1) / k;//올림 계산 
			}
		}
	}
	
	if(demand > m || demand == 0) cout<<"IMPOSSIBLE";
	else cout<<"POSSIBLE\n"<<m - demand;
	return 0;
}