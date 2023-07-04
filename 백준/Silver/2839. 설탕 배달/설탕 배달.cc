#include <stdio.h>
int n, result;
int main()
{
	result = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (5 * i + 3 * j == n)
			{
				result = i + j;
				break;
			}
		}
	}
	printf("%d", result);
	return 0;
}

