#include <iostream>
#include <string.h>
using namespace std;
char str1[1005], str2[1005];
int dp[1005][1005];
int main(){
	scanf("%s %s", str1+1, str2+1);
	int sz1 = strlen(str1+1);
	int sz2 = strlen(str2+1);
	
	for(int i=1;i<=sz1;i++){
		for(int j=1;j<=sz2;j++){
			if(str1[i]==str2[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	printf("%d", dp[sz1][sz2]);
	return 0;
}