#include <stdio.h>
#include <algorithm>
int dp[1000000 + 10];
using namespace std;
int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;// 빼기1 일때
		if (i % 2 == 0)//2로 나누어 떨어질때
			dp[i] = min(dp[i], dp[i / 2] + 1);//최소값으로 결정
		if (i % 3 == 0)//3으로 나누어 떨어질때
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	printf("%d", dp[n]);
	return 0;
}