#include <stdio.h>
int cnt;
int main()
{
	int n, tmp;
	scanf("%d", &n);
	tmp = n;

	while (true)
	{ //tmp = 68
			int a = tmp % 10; // a=8
			tmp /= 10;
			int b = tmp; // b=6
			int sum = a + b;

			tmp = 10*a + sum % 10;
			cnt++;

			if (tmp == n)
				break;
	}
	printf("%d", cnt);
	return 0;
}