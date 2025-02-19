#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[10005];
int main()
{
	int n, budget, ans;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr,arr+n);
	ans = arr[n - 1];

	scanf("%d", &budget);

	while (true)
	{
		int sum=0;
		for (int i = 0; i < n; i++)
		{ 
			if (arr[i] > ans)
				sum += ans;
			else
				sum += arr[i];
			if (sum > budget)
				break;
		}
		if (sum <= budget) //답 찾은듯
			break;
		ans--;
	}

	printf("%d", ans);
	return 0;
}

