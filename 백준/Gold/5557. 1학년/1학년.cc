#include <iostream>
using namespace std;
long long dp[105][25], answer; // dp[i][val] : i번째에서 val이 되는 경우의 수 
int n, arr[105];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	dp[0][arr[0]] = 1; 
	for(int i=1;i<n-1;i++){
		int now = arr[i];
		for(int j=0;j<=20;j++){
			if(j-now>=0) dp[i][j] += dp[i-1][j-now];
			if(j+now<=20) dp[i][j] += dp[i-1][j+now];
		}
	}
	//[0,n-2]까지의 모든 경우의 수를 구한 뒤, arr[n-1]의 값이 되는 경우의 수 
	cout<<dp[n-2][arr[n-1]];
	return 0;
}