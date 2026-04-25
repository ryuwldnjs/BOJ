#include <stdio.h>
int n, num;
int cnt;
long long sum; 
int arr[100000+50];
int main()
{
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d", &num);
		if(num)
		{
			arr[cnt]=num;
			cnt++;
		}
		else
		{
			cnt--;
			arr[cnt]=0;
		}
	}
	
	for(int i=0;i<cnt;i++)
		sum += arr[i];
	printf("%lld", sum);
	return 0;
}