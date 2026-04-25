#include <stdio.h>
int E,S,M,ans;
int main()
{
	scanf("%d %d %d", &E, &S, &M);
	
	for(int i=1;i<=15*28*19;i++)
	{
		if((i-E)%15==0&&(i-S)%28==0&&(i-M)%19==0)
		{
			ans=i;
			break;
		 } 
	}
	printf("%d", ans);
	return 0;
}