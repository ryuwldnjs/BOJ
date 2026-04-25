#include <stdio.h>
#define MOD 16769023
int ans=1,n;
int main(){
	scanf("%d", &n);
	for(int i=0;i<(n+1)/2;i++) {
		ans = (2*ans)%MOD;
	}
	printf("%d", ans);
	return 0;
}