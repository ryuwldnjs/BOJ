#include <stdio.h>
int n,m,cnt;
int main()
{
	scanf("%d %d", &n ,&m);
	if(n>=3)
	{
		if(m>=6)
			cnt=m-2;
		if(m==5)
			cnt=m-1;
		if(m<=4)
			cnt=m;
	}
	
	if(n==2)
		cnt=(m+1)/2>4 ? 4 : (m+1)/2;
	if(n==1)
		cnt=1;
	printf("%d", cnt); 
	return 0;
}