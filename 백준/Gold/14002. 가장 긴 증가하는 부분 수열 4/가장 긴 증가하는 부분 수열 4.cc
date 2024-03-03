#include <iostream>
#include <vector>
using namespace std;
vector<int> arr(1005), dp(1005,1), answer;
int n,len;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=0;j<i;j++){
			if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]+1);
		}
		len = max(len, dp[i]);
	}
	
	int target = len;
	
	for(int i=n-1;i>=0;i--){
		if(target == dp[i]){
			answer.push_back(arr[i]);
			target--;
		}
	}
	cout<<len<<'\n';
	for(auto it = answer.rbegin(); it != answer.rend(); it++){
		cout<<*it<<' ';
	}
	return 0;
}