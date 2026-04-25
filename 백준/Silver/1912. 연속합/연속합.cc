#include <stdio.h>
int arr[100001];
long long sum[100001];

long long max(long long a, long long b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	int n;
	long long result;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	// 여기까지 숫자 입력

	sum[0] = arr[0];
	result = sum[0]; //연속합의 최댓값 저장

	for (int i = 1; i < n; i++)
	{
		sum[i] = max(sum[i - 1] + arr[i], arr[i]);
		//다음 숫자를 더할때 대소 비교
		result = max(sum[i], result);
	}
	printf("%lld", result);
	return 0;
}