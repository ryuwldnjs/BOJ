#include <stdio.h>
int sum[100] = {0,1};
int fibonacci(int n)
{
	if (sum[n] > 0)//이미 계산되어 있는 상태일때
		return sum[n];
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return sum[n] = fibonacci(n - 1) + fibonacci(n - 2);

}
int main()
{
	int n;
	scanf("%d", &n);
	fibonacci(n);
	printf("%d", sum[n]);
	return 0;
}