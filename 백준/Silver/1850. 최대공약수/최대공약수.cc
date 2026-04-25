#include <stdio.h>
typedef long long ll;
ll a,b;
ll gcd(ll a, ll b)
{
   while(b>0)
   {
      ll temp = b;
      b = a%b;
      a = temp;
   }
   return a;
}
int main()
{
	scanf("%lld %lld", &a, &b);
	
	long long n= gcd(a,b);
	for(int i=0;i<n;i++)
		printf("1");
	return 0;
 } 