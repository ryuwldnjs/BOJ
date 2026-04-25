#include <stdio.h>
int t;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		int n,score[1005];
		int cnt=0,sum =0;
		scanf("%d", &n);
		for(int i =0;i<n;i++)
		{
			scanf("%d", &score[i]);
			sum+=score[i];
		}
		for(int i =0;i<n;i++)
		{
			if(score[i]>sum/n)
				cnt++;
		}		
		
		printf("%.3lf%%\n", (double)cnt/n*100);
	}
	return 0;
}