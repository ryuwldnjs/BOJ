#include <iostream>
using namespace std;
char map[1005][1005];
int dp[1005][1005];

int dy[3] = {-1,0,1};
pair<int,int> start;
struct stats{
	int c;
	bool goal;
};
int n,m;
bool pass(int y, int x){
	if(0<=y&&y<n && 0<=x&&x<m){
		if(map[y][x]!='#') return true;
	}
	return false;
}

int solve(int y, int x){
	
	int &ret = dp[y][x];
	if(ret != -1) return ret;
	ret = 0;
	if(map[y][x]=='O'){
		ret = 1000000;
		for(int i=0;i<3;i++){
			int xx = x + 1;
			int yy = y + dy[i];
		
			if(pass(yy,xx)){
				ret = max(ret, solve(yy,xx));
			}
		}
		return ret;
	}
	
	
	if(map[y][x]=='C') ret++;
	 
	int MAX = 0;
	for(int i=0;i<3;i++){
		int xx = x + 1;
		int yy = y + dy[i];
		
		if(pass(yy,xx)){
			MAX = max(MAX, solve(yy,xx));
		}
	}
	ret = ret+MAX;
	return ret;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			dp[i][j] =  -1;
			
			if(map[i][j]=='R')
				start = {i,j};
		}
		
	int ans = solve(start.first, start.second);
	if(ans>=1000000) cout<<ans-1000000;
	else cout<<-1;
	return 0;
}