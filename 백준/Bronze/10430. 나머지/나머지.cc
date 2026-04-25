#include <stdio.h>
int a,b,c;
int main()
{
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n%d\n%d\n%d\n", (a+b)%c, (a%c+b%c)%c, (a*b)%c, (a%c*b%c)%c);
	return 0;
}