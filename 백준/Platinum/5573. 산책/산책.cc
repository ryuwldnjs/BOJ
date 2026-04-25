#include <iostream>
using namespace std;
int map[1005][1005], dp[1005][1005];
int h,w,n;

pair<int,int> find(int y, int x){
	if(y>=h || x>=w) return {y,x};
	if(map[y][x]==1) return find(y,x+1);
	if(map[y][x]==0) return find(y+1,x);
}
void solve(int y,int x){
	if(y>=h || x>=w || dp[y][x]==0) return;
	
	int &ret = dp[y][x];
	
	if(ret%2==1){
		if(map[y][x]==1)
			dp[y][x+1]++;
		else
			dp[y+1][x]++;
		
	}
	dp[y+1][x] += ret/2;
	dp[y][x+1] += ret/2;
	
	solve(y+1, x), solve(y,x+1);
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>h>>w>>n;
	n--;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			cin>>map[i][j];
	dp[0][0] = n;
	//solve(0,0);
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(dp[i][j]%2==1){
				if(map[i][j]==1) dp[i][j+1]++;
				else dp[i+1][j]++;
			}
			dp[i+1][j] += dp[i][j]/2;
			dp[i][j+1] += dp[i][j]/2;
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			map[i][j] ^= dp[i][j]%2;
		}
	}
	pair<int,int> ans = find(0,0);
	cout<<ans.first+1<<' '<<ans.second+1;
	return 0;
}