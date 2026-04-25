#include <stdio.h>
#define I(R,G,B) 2126*R + 7152*G + 722*B
int n,m;

void print(int value)
{
	if(value<510000)
		printf("#");
	else if(value<1020000)
		printf("o");
	else if(value<1530000)
		printf("+");
	else if(value<2040000)
		printf("-");
	else
		printf(".");
}
int main()
{
	int r,g,b;
	scanf("%d %d", &n, &m);
	while(n--)
	{
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d", &r, &g, &b);
			print(I(r,g,b));
		}
		printf("\n");
	}
	return 0;
}