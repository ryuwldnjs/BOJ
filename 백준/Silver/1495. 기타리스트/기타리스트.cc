#include <iostream>
using namespace std;
int n,s,m, v[55];
int dp[55][1005]; 
// dp[i][j] : i번째볼륨선택시에 j가 만들어질수있는가 

bool able(int x){
	return 0<=x&&x<=m;
}
int main(){
	cin>>n>>s>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	dp[0][s] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			
			if(able(j-v[i]))
				dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]);
			if(able(j+v[i]))
				dp[i][j] = max(dp[i][j], dp[i-1][j+v[i]]);
		}
	}
	int ans=-1;
	for(int i=0;i<=m;i++){
		if(dp[n][i]) ans = i;
	}
	cout<<ans;
	return 0;
}