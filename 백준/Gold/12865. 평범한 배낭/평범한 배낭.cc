#include <iostream>
using namespace std;
int n,k,w[105],v[105];
int dp[105][100005];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i];
	}
	
	for(int i=1;i<=n;i++){ //i번째 물건
		for(int j=0;j<=k;j++){
			dp[i][j] = dp[i-1][j];
			
			if(j - w[i] >=0){
				dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
			}
		}
	}
	cout<<dp[n][k];
	return 0;
}