#include <iostream>
using namespace std;
int n, map[18][18], dp[18][18][3];

bool pass(const int y,const int x, const int dir){
	if(0<=y&&y<n && 0<=x&&x<n){//맵이탈 확인 
		//파이프가 장애물과 겹치는지 확인 
		if(dir==1 && (map[y-1][x] || map[y][x-1]))
			return false;
		if(map[y][x]) return false;
		
		return true;
	}
	return false;
}

//dir==0 :  가로
//dir==1 :  대각선
//dir==2 :  세로 
int solve(int y, int x, int dir){
	int &ret = dp[y][x][dir];
	if(ret != -1) return ret;
	ret = 0;
	//기저사례 : 목표지점 도착 
	if(y==n-1 && x==n-1){
		return ret = 1;
	}
	
	if(dir == 0){
		if(pass(y, x+1,0)) ret += solve(y, x+1, 0);
		if(pass(y+1, x+1,1)) ret += solve(y+1, x+1, 1);
	}
	else if(dir == 1){
		if(pass(y, x+1,0)) ret += solve(y, x+1, 0);
		if(pass(y+1, x+1,1)) ret += solve(y+1, x+1, 1);
		if(pass(y+1, x,2)) ret += solve(y+1, x, 2);
	}
	else if(dir == 2){
		if(pass(y+1, x+1,1)) ret += solve(y+1, x+1, 1);
		if(pass(y+1, x,2)) ret += solve(y+1, x, 2);
	}
	return ret;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
		}
		
	cout<<solve(0, 1, 0);
	return 0;
}