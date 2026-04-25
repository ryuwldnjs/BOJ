#include <stdio.h>
int arr[10000+5];
int n;
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d", &a);
		arr[a]++;
	}

	for(int i=1;i<=10000;i++)
	{
		for(int j=1;j<=arr[i];j++)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}