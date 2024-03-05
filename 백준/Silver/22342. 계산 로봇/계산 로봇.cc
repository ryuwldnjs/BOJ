#include <bits/stdc++.h>
using namespace std;
int m,n, ans;
int arr[2005][2005];
int dp[2005][2005];
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			char x;
			cin>>x;
			arr[i][j] = x - '0';
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			int MAX = 0;
			if(i-1>=1) MAX = max(MAX, dp[i-1][j-1]);
			MAX = max(MAX, dp[i][j-1]);
			if(i+1<=m) MAX = max(MAX, dp[i+1][j-1]);
			dp[i][j] = MAX + arr[i][j];
		}
	}
	
	for(int i=1;i<=m;i++){
		ans = max(ans, dp[i][n] - arr[i][n]);
	}
	cout<<ans;
	return 0;
}