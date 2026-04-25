#include <stdio.h>
#define mod 1000000007
int sum;
int dp[55]={1,1};
int fibonacci(int n)
{ // 호출
if(dp[n])
	return dp[n];
  if (n < 2) {
    return 1;
  }  
  return dp[n]=(fibonacci(n-2) + fibonacci(n-1)+1)%mod;
}

int main()
{
	int n; 
	scanf("%d", &n);
	fibonacci(n);
	printf("%d", dp[n]);
	return 0;
 } 