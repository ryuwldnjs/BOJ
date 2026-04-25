#include <stdio.h>
char str[100];
int main()
{
	while(scanf("%[^\n]s", str) != EOF)
	{
		getchar();
		printf("%s\n",str);
	}
	return 0;
}