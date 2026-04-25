#include <stdio.h>
int n,max;
int num[10]; // 0 1 2 3 4 5 6 7 8 9 -> 9는 6으로 바꾸기 
int main()
{
	scanf("%d", &n);
	while(n)
	{
		if(n%10==9)
			num[6]++;
		else
			num[n%10]++;
		n/=10;
	 } 
	 num[6]= (num[6]+1)/2;
	 for(int i=0;i<9;i++)
	 {
	 	if(num[i]>max)
	 		max = num[i];
	 }
	 printf("%d", max);
	return 0;
}