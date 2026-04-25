#include <iostream>
#define INF 1234567890
using namespace std;

int arr[1005][3], dp[1005][3], answer=1234567890;
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}

	
	
	for(int k=0;k<3;k++){
		//첫번째가 k색 일때
		
		for(int j=0;j<3;j++){
			if(k==j) dp[1][j]=INF;
			else dp[1][j] = arr[0][k] + arr[1][j];
		}
		for(int i=2;i<n;i++){
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
		}
		for(int j=0;j<3;j++){
			if(k==j) continue;
			answer = min(answer, dp[n-1][j]);
		}
		
	}
	

	cout<<answer;
	return 0;
}