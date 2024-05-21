#include <iostream>
using namespace std;
int a,n,m,v[5005], p[5005];
double money, b;
int dp[5005][10005];
int main(){
	while(true){
		cin>>n>>money;
		int answer = 0;
		m = money * 100 + 0.5;
		if(n==0 && m==0) break;
		
		for(int i=1;i<=n;i++){
			cin>>a>>b;
			v[i] = a;
			p[i] = b * 100 + 0.5;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				dp[i][j] = dp[i-1][j];
				if(j - p[i] >= 0){
					dp[i][j] = max(dp[i][j], dp[i-1][j-p[i]] + v[i]);
					dp[i][j] = max(dp[i][j], dp[i][j-p[i]] + v[i]);
					
				}
				
				answer = max(answer, dp[i][j]);
			}
		}
		cout<<answer<<'\n';
	}
	return 0;
}