#include <stdio.h>
#include <map>
using namespace std;
long long N,P,Q;
map<long long, long long> m;

long long dp(long long n)
{
	if(m[n])
		return m[n];
	return m[n]= dp(n/P) + dp(n/Q);
}


int main()
{
	scanf("%lld %lld %lld", &N, &P, &Q);
	m[0]=1;
	printf("%lld", dp(N));
	return 0;
}