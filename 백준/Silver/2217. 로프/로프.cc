#include <stdio.h>
#include <algorithm>
int arr[100005];
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);
	int ans = 0; //이게 답이 될거임
	for (int i = n-1; i >= 0; i--)
	{
		ans = max(ans, arr[i] * (n - i));
	}
	printf("%d", ans);
	return 0;
}