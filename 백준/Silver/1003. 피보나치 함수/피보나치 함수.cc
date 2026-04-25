#include <stdio.h>
int dp[45][2];
//dp[n][0]=dp[n-1][0]+dp[n-2][0]
//dp[n][1]=dp[n-1][0]+dp[n-1][1]

int main()
{
	int k,n;
	scanf("%d", &k);//데이터케이스 개수
	dp[0][0]=1, dp[0][1]=0;
	dp[1][0]=0, dp[1][1]=1;
	for(int i=2;i<45;i++){
		dp[i][0]=dp[i-1][0]+dp[i-2][0];
		dp[i][1]=dp[i-1][0]+dp[i-1][1];
	}
	for (int i = 0; i < k; i++)
	{
		//cnt[0] = cnt[1] = 0;//청소
		scanf("%d", &n);
	//	fibonacci(i);

		printf("%d %d\n", dp[n][0], dp[n][1]);
	}
	return 0;
}