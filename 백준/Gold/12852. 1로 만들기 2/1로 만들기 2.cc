#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000000];
int pre[1000000];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int x;
	cin>>x;
	
	for(int i=2;i<=x;i++){
		dp[i] = dp[i-1]+1;
		pre[i] = i-1;
		
		if(i%3==0 && dp[i] > dp[i/3]+1){
			dp[i] = dp[i/3]+1;
			pre[i] = i/3;
		}
		
		if(i%2==0 && dp[i] > dp[i/2]+1 ){
			dp[i] = dp[i/2]+1;
			pre[i] = i/2;
		}
		
	}
	
	
	cout<<dp[x]<<'\n';
	while(x){
		cout<<x<<' ';
		x = pre[x];
	}
	return 0;
}