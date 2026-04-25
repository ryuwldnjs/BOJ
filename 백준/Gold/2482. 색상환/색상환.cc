#include <iostream>
#define MOD 1000000003
using namespace std;
int n,k;
int dp[1005][1005];

int solve(int idx, int c){
	if(c==0) return 1;
	int &ret = dp[idx][c];
	if(ret != -1) return ret;
	ret = 0;
	
	if(idx-2>0)
		ret = (ret + solve(idx-2, c-1))%MOD;
	if(idx-1>0)
		ret = (ret + solve(idx-1, c))%MOD; 
	return ret;
}

int main(){
	cin>>n>>k;
	for(int i=0;i<=n;i++) fill(dp[i], dp[i]+k+1, -1);
	
	for(int i=1;i<=n;i++){
		dp[i][1] = i;
	}
	
	//0번을 뽑은경우 +0번을 뽑지않은경우 
	cout<<(solve(n-3, k-1)+solve(n-1, k))%MOD;
	return 0;
}