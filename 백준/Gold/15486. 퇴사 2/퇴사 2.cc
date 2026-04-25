#include <iostream>
using namespace std;
int dp[1500000+5];
int t[1500000+5], p[1500000+5];
int n;
int solve(int day){
	if(dp[day] != -1) return dp[day];
	
	if(day>n) return 0;
	
	int &ret = dp[day];
	ret = solve(day+1);
	if(day+t[day] <= n)
		ret = max(ret, solve(day+t[day]) + p[day]);
		
	return ret;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	fill(dp, dp+n+1, -1);
	for(int i=0;i<n;i++){
		cin>>t[i];
		cin>>p[i];
	}
	cout<<solve(0);
	return 0;
} 