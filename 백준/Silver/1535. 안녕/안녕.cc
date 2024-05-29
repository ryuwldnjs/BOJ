#include <iostream>
using namespace std;
int dp[25][105]; //dp[i][j] : i번째 사람까지봤을때, 체력j일때의 최대 기쁨 
int n,lose[25], joy[25];
int answer;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>lose[i];
	}
	for(int i=0;i<n;i++){
		cin>>joy[i];
	}
	if(100-lose[0]) answer = dp[0][100-lose[0]] = joy[0];
	
	for(int i=1;i<n;i++){
		for(int j=1;j<=100;j++){
			dp[i][j] = dp[i-1][j];
			if(j+lose[i] <= 100)
				dp[i][j] = max(dp[i][j], dp[i-1][j+lose[i]] + joy[i]);
			answer = max(answer, dp[i][j]);
		}
	}
	cout<<answer;
	return 0;
}