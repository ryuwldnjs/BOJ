#include <stdio.h>
int cnt;//자릿수 
int n,m,tmp,tmp2;
int num[5];
int main()
{
	scanf("%d %d", &n, &m);
	tmp=tmp2=n;
	while(tmp)
	{
		tmp/=10;
		cnt++;
	}
	int tmp_cnt=cnt;
	while(n)
	{
		num[cnt-1] = n%10;
		n/=10;
		cnt--;
	}
	
	for(int i=0;i<m && i<tmp2*tmp_cnt;i++)
		printf("%d", num[i%tmp_cnt]);
	return 0;
}