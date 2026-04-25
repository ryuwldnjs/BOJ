#include <stdio.h>
int a, b,k;

int gcd(int a, int b)
{
	return a%b == 0 ? b : gcd(b, a%b);
}
int main()
{
	scanf("%d %d", &a, &b);
	k = gcd(a, b);
	printf("%d\n%d", k, a*b / k);
}