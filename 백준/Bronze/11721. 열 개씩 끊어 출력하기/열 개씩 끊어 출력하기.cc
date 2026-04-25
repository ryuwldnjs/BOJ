#include <stdio.h>
char str[105];
int main()
{
	scanf("%s", str);
	for(int i=0;str[i];i++)
	{
		printf("%c", str[i]);
		if(i%10==9)
			printf("\n");
	}
	return 0;
}