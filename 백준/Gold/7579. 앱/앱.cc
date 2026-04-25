#include <iostream>
using namespace std;
int n,m;
int w[100+5], v[100+5];
int dp[100+5][10000+5];
long long total_w, total_v;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		total_v += v[i];
	}
	for(int i=1;i<=n;i++){//거꾸로.. 비용을 weight로, 메모리를 value로 
		cin>>w[i];
		total_w += w[i];
	}
	long long capacity = total_w;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=capacity;j++){
			dp[i][j] = dp[i-1][j];
			
			if(j - w[i] >= 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
			}
			
		}
	}
	for(int i=0;i<=capacity;i++){
		if(dp[n][i] >= m){
			cout<<i;
			return 0;
		}
	} 
	return 0;
}