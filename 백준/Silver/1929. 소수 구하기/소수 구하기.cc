#pragma warning(disable:4996) 
#include <stdio.h>
const int MAX = 2000000+50;
int era[MAX];
int m, n;
int main() {


	scanf("%d %d", &m, &n);
	for (int i = 2; i <= n; i++)
		era[i] = i;

	for (int i = 2; i <= n; i++)
	{
		if (era[i] > 0) //소수인경우
		{
			for (int j = i+i; j <= n; j+=i)
			{
				era[j] = 0;
			}
		}
	}
	for (int i = m; i <= n; i++)
	{
		if (era[i] != 0)
			printf("%d\n", era[i]);
	}
	return 0;
}
