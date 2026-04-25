#include<stdio.h>
#include <algorithm>
using namespace std;
int n,a;
int top,sum;
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a);
		sum+=a;
		top = max(top, a);
	}
	printf("%lf", (double)sum/(n*top)*100);
	return 0;
}