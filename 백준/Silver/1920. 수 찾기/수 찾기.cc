#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m,ans;
int arr[100005];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);

	scanf("%d", &m);
	while (m--)
	{
		scanf("%d", &ans);
		printf("%d\n", binary_search(arr, arr + n, ans));
	}

	return 0;
}