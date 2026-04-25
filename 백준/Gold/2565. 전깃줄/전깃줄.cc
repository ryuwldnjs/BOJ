#include <stdio.h>
#include <algorithm>
using namespace std;
pair<int, int> line[105];
int dp[105], cut;
int main()
{
	int n,a, b;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		line[i] = { a,b };
	}
	sort(line+1, line + n+1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <=i; j++)
		{
			if (line[i].second > line[j].second) //엇갈림 발견
				dp[i] = max(dp[i], dp[j] + 1);
		}

		cut = max(cut, dp[i]);
	}
	printf("%d",n- cut);
	return 0;
}