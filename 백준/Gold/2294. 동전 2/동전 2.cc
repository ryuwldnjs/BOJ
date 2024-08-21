#include <stdio.h>
#include <algorithm>
using namespace std;
int coin[105];
int dp[100005];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
        scanf("%d", &coin[i]);
    
	fill(dp + 1, dp + k+1, 100001);

		for (int i = 1; i <= n; i++)
			for (int j = coin[i]; j <= k; j++)
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);

		if (dp[k] == 100001) dp[k] = -1;
		printf("%d", dp[k]);
	return 0;
}