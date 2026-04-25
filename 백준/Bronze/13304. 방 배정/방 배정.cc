#include <stdio.h>
int n,k, s, y;
int arr[5];
int main()
{
	scanf("%d %d", &n, &k);
	for(int i =0; i<n;i++)
	{
		scanf("%d %d", &s, &y);
		if(y<=2)//1,2학년 
		{
		arr[0]++; 
		continue;
	}
		if(y>=3&&y<=4) //34학년
		{
			if(s==0)//여자
			arr[1]++;
			else
			arr[2]++; 
			continue;
		 } 
		 if(s==0)
		 arr[3]++;
		 else
		 arr[4]++;
	}
	
	int ans=0;
	for(int i=0;i<5;i++)
	{
		ans+=arr[i]/k;
		if(arr[i]%k != 0) //나누어 떨어지지않을때 
		ans++;
	}
	printf("%d", ans);
	return 0;
}