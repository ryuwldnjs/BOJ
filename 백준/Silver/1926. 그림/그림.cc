#include <iostream>
#include <algorithm> 
using namespace std;
int n,m,map[505][505];
int ans_cnt, ans_area;
int area;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool pass(int y, int x){ //map의 경계선 내부에 있는지 check 
	if(1<=y&&y<=n && 1<=x&&x<=m)
		return true;
	return false;
}
void dfs(int x, int y){
	map[x][y] = 0;
	area++; //그림의 넓이 계산 
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if(pass(xx, yy) && map[xx][yy]) dfs(xx, yy);
	}
}


int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){ // flood fill - DFS
		for(int j=1;j<=m;j++){
			area = 0;
			
			if(map[i][j]){ //이어져있는 모든 부분 탐색 
				dfs(i, j);
				ans_cnt++;
			}
			
			ans_area = max(ans_area, area);
		}
	}
	
	cout<<ans_cnt<<"\n"<<ans_area;
	return 0;
} 