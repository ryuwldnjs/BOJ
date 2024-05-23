#include <iostream>
#include <vector> 
#define INF 1e9
using namespace std;
vector<int> dp(100000+5, INF);
int n;
int main(){
	cin>>n;
	dp[2] = 1;
	dp[4] = 2;
	dp[5] = 1;
	for(int i=5;i<=n;i++){
		dp[i] = min(dp[i], dp[i-2] + 1);
		dp[i] = min(dp[i], dp[i-5] + 1);
	}
	cout<< (dp[n]==INF ? -1 : dp[n]);
	return 0;
}