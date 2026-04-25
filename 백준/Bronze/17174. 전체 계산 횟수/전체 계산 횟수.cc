#include <stdio.h>
int n,m;
int main()
{
	scanf("%d %d", &n, &m);
	int sum = n+ n/m;
	
	int tmp=n/m;
	while(tmp)
	{
		sum +=tmp/m;
		tmp/=m;
	}
	printf("%d", sum);
	return 0;
}