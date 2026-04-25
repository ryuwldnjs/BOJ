#include <iostream>
#include <algorithm>
using namespace std;
int p[1000+50],n;
int dp[1000+50];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	
	// dp[i] = dp[i-1] + p[1]
	//         dp[i-2] + p[2]..중 min 값 
	for(int i=1;i<=n;i++){
		dp[i] = p[i]; //base 설정 
		for(int j=1;j<i;j++){
			dp[i] = min(dp[i], dp[i-j] + p[j]);
		}
	}
	
	cout<<dp[n];
	return 0;
}