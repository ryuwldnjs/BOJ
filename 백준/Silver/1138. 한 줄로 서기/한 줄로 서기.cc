#include <stdio.h>
int n,arr[15], ans[15];
int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		
		for(int j=1;j<=n;j++)	{
		int k=0;
		bool flag=false;
		
		if(cnt==arr[i])
		{
			while(true)
			{
				if(ans[j+k]==0)
				{
					ans[j+k]=i;
					flag=true;
					break;
				}
				k++;
			}

		}
			if(flag) break;
			if(ans[j]==0) cnt++;
		}
		
	}
	for(int i=1;i<=n;i++)
		printf("%d ", ans[i]);
	return 0;
}