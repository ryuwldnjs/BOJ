#include <stdio.h>
#include <algorithm>
using namespace std;
int n,ans, arr[1005];
int dp[1005];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		dp[i]=arr[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				dp[j] = max(dp[j], dp[i]+arr[j]);
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}