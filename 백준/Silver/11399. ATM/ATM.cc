#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int arr[1000];
int sum, per;//총합, 개인 소요시간
int main()
{


	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		per += arr[i];
		sum += per;
	}
	printf("%d", sum);
	return 0;
}
