#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 1234567890
int dp[50000+50]={0,1};
int n;
int main(){
	scanf("%d", &n);
	for(int i=2;i<=n;i++){
		dp[i]=INF; //아직 구해지지않았다는 의미에서 무한대 설정 
		for(int j=1;j*j<=i;j++){
			dp[i] = min(dp[i], dp[i-j*j]+1);
		}
	}
	
	printf("%d", dp[n]); 
	return 0;
}