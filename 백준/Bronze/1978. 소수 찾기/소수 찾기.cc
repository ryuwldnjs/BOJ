#include <stdio.h>
int n,a,flag,cnt;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a == 1)
			continue;
		flag = 1;
		for (int i = 2; i*i <= a; i++)
		{
			if (a%i == 0) //어 나누어 떨어지네?
			{
				flag = 0;
				break;
			}
		}
		if(flag) cnt++;
	}
	printf("%d", cnt);
	return 0;
}