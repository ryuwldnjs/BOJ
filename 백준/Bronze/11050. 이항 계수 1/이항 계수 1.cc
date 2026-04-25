#include <stdio.h>
int main()
{
	int n, k;
	int a=1, b=1; //분모 분자
	scanf("%d %d", &n, &k);
	for (int i = n; i > n-k; i--)
		a *= i;
	for (int i = 1; i <= k; i++)
		b *= i;

	printf("%d",a/b);
	return 0;
}