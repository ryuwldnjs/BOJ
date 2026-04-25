#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
long long ans; 
long long card[1005];
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%lld", &card[i]);
		
	for(int i=0;i<m;i++)
	{
		sort(card, card+n);
		long long sum=card[0]+card[1];
		card[0]=card[1]=sum;
	}
	
	for(int i=0;i<n;i++)
		ans+=card[i];
		
	printf("%lld", ans);
	return 0;
}