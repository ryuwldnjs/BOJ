#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
long long m, s,e,ans;
long long arr[1000005];
int main()
{
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
		e = max(e, arr[i]);
	}
	while (s <= e)
	{
		long long mid = (s + e) / 2;
		long long sum = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mid) //나무 자를수 있을때
				sum += arr[i] - mid;
		}
		if (sum == m)
		{
			ans = mid;
			break;
		}
		if (sum > m)
		{
			ans = max(ans, mid);
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	printf("%lld", ans);
	return 0;
}