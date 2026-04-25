#include <stdio.h>
#include <algorithm>
using namespace std;
int n, k, arr[11];
int cnt;
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = n; i > 0; i--)
	{
		if (k >= arr[i])
		{
			cnt += k / arr[i];
			k %= arr[i];
		}
		if (k == 0)//다 했을때
			break;
	}
	printf("%d", cnt);
	return 0;
}

