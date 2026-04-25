#include <stdio.h>
int n,a[1005], dp[1005],max;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
		dp[i]=1;
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]<a[i]) dp[j] = dp[j]>dp[i]+1 ? dp[j] : dp[i]+1;
		}
	}
	for(int i=0;i<n;i++){
		if(dp[i]>max) max = dp[i];
	}
	printf("%d", max);
	return 0;
}