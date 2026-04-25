#include <stdio.h>
#include <algorithm>
#define INF 1234567890
using namespace std;
int a[1000+50];
int dp[1000+50];
int n;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
		if(i) dp[i]=INF; //무한히 먼 곳으로 가정 
	}

	for(int i=0;i<n;i++){
		for(int j=1;j<=a[i];j++){
			dp[i+j] = min(dp[i+j], dp[i]+1); //더 짧을때만 갱신 
		}
	}
	//for(int i=0;i<n;i++) printf("[%d %d] ",a[i], dp[i]);
	if(dp[n-1]==INF) dp[n-1]=-1; //INF=갈 수 없는 곳일때는 -1출력 
	printf("%d", dp[n-1]);
	return 0;
}