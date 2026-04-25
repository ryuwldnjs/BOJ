#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int floor[305];
int dp[305][3]; //1칸, 2칸 연속 - 편의상 한칸은 유령취급 
int main()
{
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++) {
		scanf("%d", &floor[i]);
	}
	dp[1][1] = floor[1];
	dp[2][1]=floor[2]; 
	dp[2][2] = floor[1] + floor[2];
	for(int i=3;i<=n;i++) {
		dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + floor[i];
		dp[i][2] = dp[i-1][1] + floor[i];
	}
	
	printf("%d", max(dp[n][1], dp[n][2]));
	return 0;
}