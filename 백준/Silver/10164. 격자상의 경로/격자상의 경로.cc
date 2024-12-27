#include <iostream>
using namespace std;

int n,m,k;
int dp[20][20];
int ans;
int main(){
	cin>>n>>m>>k;
	
	int n1,m1,n2,m2;
	n1 = k/m + 1;
	m1 = k%m;
	n2 = n - n1 + 1;
	m2 = m - m1 + 1;
	
	dp[1][0] = 1;
	if(k==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		cout<<dp[n][m];
		return 0;
	}
	
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=m1;j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	ans = dp[n1][m1];
	
	for(int i=1;i<=n2;i++){
		for(int j=1;j<=m2;j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	ans *= dp[n2][m2];
	
	cout<<ans;
	return 0;
}