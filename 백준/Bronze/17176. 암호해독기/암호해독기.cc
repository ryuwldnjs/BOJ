#include <stdio.h>
int arr[52+5]; //각 알파벳 갯수
int n,num, a; 
char tmp[100005];
int main()
{

	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &num);
		arr[num]++;
	}
	getchar();
	fgets(tmp, 100005, stdin);

	
	for(int i=0;tmp[i];i++)
	{
		if('a'<=tmp[i]&& tmp[i]<='z')
			tmp[i]-=70;
		else if('A'<=tmp[i]&& tmp[i]<='Z')
			tmp[i]-=64;
		else if(tmp[i]=' ')
			tmp[i]=0;
	//	printf("%d", tmp[i]);
		arr[tmp[i]]--;
	}
	arr[0]++;
	for(int i=0;i<54;i++)
		if(arr[i])
			{
				printf("n");
				return 0;
			}
	printf("y");
	return 0;
}