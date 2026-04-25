#include <stdio.h>
int n,sum;
int main()
{
	scanf("%d", &n);
	sum+=n/5;
	sum+=n/25;
	sum+=n/125;
	printf("%d", sum);
	return 0;
}