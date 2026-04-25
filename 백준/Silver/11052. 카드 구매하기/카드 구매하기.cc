#include <stdio.h>
#include <algorithm>

int p[1005];
int dp[1005];
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &p[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i] = max(dp[i], dp[i-j] + p[j]);
		}
	}
	printf("%d", dp[n]);
	return 0;
}
//DP[N] = DP[N-1] + P[1]
//        =  DP[N-2] + P[2]
//... DP[N-i] +P[i] 중 맥스값