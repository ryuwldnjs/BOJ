#include<stdio.h>
int n,x;
int main()
{
	int tmp;
	scanf("%d %d",&n, &x);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &tmp);
		if(tmp<x)
		{
			printf("%d ", tmp);
		}
	 } 
	return 0;
}