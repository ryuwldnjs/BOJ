#include <stdio.h>
int n,m;
int gcd(int a,int b)
{
	while(b)
	{
		int tmp = a;
		a= b;
		b = tmp%b;
	}
	return a;
}
int main()
{
	scanf("%d:%d", &n,&m);
	int divide = gcd(n,m);
	printf("%d:%d", n/divide,m/divide);
	return 0;
}