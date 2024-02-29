#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, arr[250000+5];
ll dp[2500000+5];
ll answer, sum;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
	}
	
	//마지막 방에는 안산다고 가정 
	dp[0] = !arr[0];
	if(arr[1]){
		dp[1] = dp[0];
	}
	else dp[1] = 1;
	
	for(int i=2;i<n-1;i++){
		if(arr[i]) dp[i] = dp[i-1];
		else if(arr[i-1]) dp[i] = dp[i-1] + 1;
		else dp[i] = max(dp[i-2] + 1, dp[i-1]);
	}
	answer = dp[n-2];
	
	//첫번째 방에는 안산다고 가정 
	dp[0] = 0;
	dp[1] = !arr[1];
	
	for(int i=2;i<n;i++){
		if(arr[i]) dp[i] = dp[i-1];
		else if(arr[i-1]) dp[i] = dp[i-1] + 1;
		else dp[i] = max(dp[i-2] + 1, dp[i-1]);
	}
	
	answer = max(answer, dp[n-1]);
	cout<<answer + sum;
	return 0;
} 