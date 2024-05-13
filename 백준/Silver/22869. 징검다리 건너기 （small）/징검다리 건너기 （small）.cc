#include <iostream>
using namespace std;
int n,k;
int rock[5000+5], dp[5000+5]={1};
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>rock[i];
		for(int j=0;j<i;j++){
			if((i-j) * (1 + abs(rock[i]-rock[j])) <= k)
				dp[i] = max(dp[i], dp[j]);
		}
	}
	cout<<(dp[n-1] ? "YES" : "NO");
	return 0;
}
