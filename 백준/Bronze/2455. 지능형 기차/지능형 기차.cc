#include <stdio.h>
int main()
{
	int a, b;
	int sum = 0, max=0;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d", &a, &b);
		sum += b-a;
		if(sum>max) max = sum;
	}
	printf("%d", max);
	return 0;
}