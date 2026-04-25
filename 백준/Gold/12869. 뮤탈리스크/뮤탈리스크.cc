#include <stdio.h>
#include <algorithm>
using namespace std;
int n,scv[5],cnt;
int dp[65][65][65]; //각 scv의 체력별 dp 
int ans;
int damage[11][8]={ {9,3,1},
				{9,1,3},
				{3,1,9},
				{3,9,1},
				{1,9,3},
				{1,3,9}}; //뮤탈리스크의  데미지

int solve(int a, int b, int c){
	if(!a && !b && !c) return 0; //전부 0일때 
	if(dp[a][b][c]) return dp[a][b][c];
	
	dp[a][b][c]=1234567890;
	for(int i=0;i<6;i++) {
		//a = max(0,a-damage[i][0]);
		//b = max(0,b-damage[i][1]);
		//c = max(0,c-damage[i][2]);
		dp[a][b][c] = min(dp[a][b][c], solve(max(0,a-damage[i][0]),max(0,b-damage[i][1]),max(0,c-damage[i][2]))+1);
	}
	return dp[a][b][c];
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &scv[i]);
	}
	
	ans = solve(scv[0], scv[1], scv[2]);
	printf("%d", ans);
	return 0;
}