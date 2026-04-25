#include <stdio.h>
#include <algorithm>
using namespace std;
int A[1000+50];
int dp[1000+50];
int n,ans; 
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &A[i]);
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(A[i]<A[j]) dp[j] = max(dp[i]+1, dp[j]); 
		}
	}
	for(int i=0;i<n;i++) ans = max(ans,dp[i]);
	printf("%d", ans+1);
	return 0;
}