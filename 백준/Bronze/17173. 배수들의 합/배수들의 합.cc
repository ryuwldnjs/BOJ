#include <stdio.h>
int n,m,sum;
int arr[1005];
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++)
	{
		scanf("%d", &arr[i]);
	}
	for(int i=arr[0];i<=n;i++)
	{
		bool flag=false;
		for(int j=0;j<m;j++)
			if(i%arr[j]==0)
				flag=true;
				
		if(flag)
			sum+=i;
	}
	printf("%d", sum);
	return 0;
}