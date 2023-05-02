#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int p[1005][3]; //RGB
int dp[1005][3]; 
int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d", &p[i][j]);
		}
	}
	dp[1][0] = p[1][0];
	dp[1][1] = p[1][1];
	dp[1][2] = p[1][2];
	
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]) +p[i][0];
			dp[i][1] = min(dp[i-1][2], dp[i-1][0]) +p[i][1];
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]) +p[i][2];
		}
		
	}
	printf("%d", min(dp[n][0], min(dp[n][1], dp[n][2])));
	return 0;
}