#include <stdio.h>
#define MOD 10007
int n,k;
int dp[1005][1005]; //nCr

int nCr(int n, int r)
{
	if(dp[n][r] != 0) //계산값 존재
	return dp[n][r];
	if(r==0 || n==r)
	{
		dp[n][r]=1;
		return 1;
	}
	return dp[n][r] =  nCr(n-1, r)%MOD + nCr(n-1,r-1)%MOD;
}
int main()
{
	scanf("%d %d", &n, &k);
	
	int ans = nCr(n,k)%MOD;
	
	
	printf("%d", ans);
	return 0;
}