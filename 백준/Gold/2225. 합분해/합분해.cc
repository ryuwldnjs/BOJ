#include <iostream>
#define MOD 1000000000
using namespace std;
int n,k,dp[205][205];
// dp[n][k] : n을 k개로 만들수있는 경우의 수 

//사용한 개수used는 k만 넘지않으면 상관없음 - 0으로 마저 채우면 되기때문 
int solve(int rest_sum, int used){	
	int &ret = dp[rest_sum][used];
	
	if(rest_sum==0 || used==k-1) return 1;
	if(rest_sum<0 || used>k) return 0;
	
	if(ret != -1) return ret;
	ret = 0;
	
	for(int i=0;i<=rest_sum; i++){
		ret += solve(rest_sum-i, used+1);
		ret%=MOD;
	}
	
	return ret;
}

int main(){
	cin>>n>>k;
	fill(dp[0], dp[0]+205*205,-1);
	cout<<solve(n,0);
	return 0;
}