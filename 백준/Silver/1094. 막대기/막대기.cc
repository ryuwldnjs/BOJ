#include <stdio.h>
int i,x,cnt,arr[7]={64,32,16,8,4,2,1};
int main()
{	scanf("%d",&x);
	for(i=0;i<7;i++)
		if(x>=arr[i])x-=arr[i],cnt++;
	printf("%d",cnt);
	return 0;}