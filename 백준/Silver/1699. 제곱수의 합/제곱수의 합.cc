#include <stdio.h>
int n;
int dp[100000+50];
int min;
int main(){
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++){
		min = 1234567890;
		for(int j=1;j*j<=i;j++){
			if(dp[i-j*j]<min) min = dp[i-j*j];
		}
		dp[i]= min+1;
	}
	printf("%d", dp[n]);
//	for(int i=0;i<n;i++){
//		printf("[%d:%d]\n ", i,dp[i]);
//	}
	return 0;
}