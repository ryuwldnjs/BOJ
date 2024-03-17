#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
string str;
vector<vector<int>> dp(2505, vector<int>(2505,INF));// dp[l][r] : 문자열[l~r]의 팰린드롬 개수 

int main(){
	cin>>str;
	int n = str.size();
	//팰린드롬 init 
	for(int i=0;i<n;i++) dp[i][i] = 1;
	for(int i=0;i<n-1;i++){
		if(str[i] == str[i+1]) dp[i][i+1] = 1;
	}
	//슬라이딩 윈도우 맹키로, 팰린드롬 판정 배열 확장 
	for(int gap=2; gap<n ;gap++){
		for(int i=0;i+gap<n;i++){
			if(dp[i+1][i+gap-1] != INF && str[i]==str[i+gap])
				dp[i][i+gap] = 1;
		}
	}
	
	for(int i=0;i<n;i++){//dp[l][r] = min{dp[l][k] + dp[k+1][r]}
		for(int j=0;j<i;j++){
			dp[0][i] = min(dp[0][i], dp[0][j] + dp[j+1][i]);
		}
	}
	
	cout<<dp[0][n-1];
	return 0;
}