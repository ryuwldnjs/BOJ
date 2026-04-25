#include <stdio.h>
int n,ans = 1;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		ans *= i;

	printf("%d", ans);
	return 0;
}