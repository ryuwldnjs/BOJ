#include <stdio.h>
int n,a,sum;
int main()
{
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%1d", &a);
		sum+=a;
	}
	
	printf("%d", sum); 
	return 0;
}