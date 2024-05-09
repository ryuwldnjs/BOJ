#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp(2000+5, vector<int>(1000+5, -1));
bool teacher[2000+5][1000+5];
int n,m,x,y;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		teacher[x][y] = true;
	}
	dp[0][0] = 0;
	for(int i=1;i<=2*n;i++){
		for(int j=0;j<=n-abs(n-i);j++){
			if(teacher[i][j]) continue;
			if(j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
			dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
			if(dp[i][j] != -1) dp[i][j] = max(dp[i][j], j);
		}
	}

	cout<<dp[2*n][0];
	return 0;
}