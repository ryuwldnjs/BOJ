#include <iostream>
#define INF 0x7FFFFFFF
using namespace std;

int n, r[505], c[505];
int dp[505][505]; //dp[k][size] : k번째 행렬부터 size개만큼 연속된 행렬곱 

int solve(int k, int size){ // dp[k][size] = min(_sigma_dp[k][i]+dp[k+i][size-i] + 행렬곱비용) 
	int &result = dp[k][size];
	if(result != INF) return result;
	if(size == 1) return 0;
	
	for(int i=1;i<size;i++){
		int x = k;
		int y = k + i;
		int z = k + size - 1;
		int cost = r[x] * r[y] * c[z];
		result = min(result, solve(k,i) + solve(k +i, size - i) + cost);
	}	
	return result;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>r[i]>>c[i];
	fill(&dp[0][0], &dp[504][504], INF);
	cout<<solve(0, n);
	return 0;
}