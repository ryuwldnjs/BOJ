#include <stdio.h>
int n,cnt;
bool hansu[1005];
int main()
{	
	scanf("%d", &n);
	for(int i=1;i<=99;i++)
		hansu[i] = true;
	
	for(int i=100;i<=n;i++)
	{
		int num=i;
		int first = num%10;
		num/=10;
		int second = num%10;
		num/=10;
		int third = num;
		
		if(first-second == second-third) hansu[i]=true; //등차수열 
	}
	
	for(int i=1;i<=n;i++)
		if(hansu[i]) cnt++;
		
	printf("%d", cnt);
	return 0;
}