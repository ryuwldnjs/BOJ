#include <iostream>
using namespace std;
int dp[100000+5][3], arr[100000+5][2];

int t,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		fill(dp[0], dp[0]+n*3, -1);
		
		for(int i=0;i<n;i++) cin>>arr[i][0];
		for(int i=0;i<n;i++) cin>>arr[i][1];
		
		dp[0][0] = 0;//안붙힌거 
		dp[0][1] = arr[0][0];//위에꺼 붙힌거 
		dp[0][2] = arr[0][1];//밑에꺼 붙힌거 
		
		for(int i=1;i<n;i++){
			dp[i][0] = max(dp[i][0], max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2])));
			dp[i][1] = max(dp[i][1], max(dp[i-1][0], dp[i-1][2])+arr[i][0]);
			dp[i][2] = max(dp[i][2], max(dp[i-1][0], dp[i-1][1])+arr[i][1]);
		}
		
		cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<'\n';
	}
	return 0;
}