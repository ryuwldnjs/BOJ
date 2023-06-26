#include <iostream>
#define EMPTY -99999
using namespace std;

int dp[101][101][101];
int a, b, c;
int w(int a, int b, int c){
	if(a<=0 || b<=0 || c<=0)
		return 1;
	if(dp[a+50][b+50][c+50] != EMPTY)
		return dp[a+50][b+50][c+50];
		
	if(a>20 || b>20 || c>20)
		return dp[a+50][b+50][c+50] = w(20, 20, 20);
		
	if(a<b && b<c)
		return dp[a+50][b+50][c+50] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	
	return dp[a+50][b+50][c+50] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	
}
int main(){
	fill(&dp[0][0][0], &dp[100][100][101], EMPTY);
	
	while(true){
		scanf("%d %d %d", &a,&b,&c);
		if(a==-1 && b==-1 && c==-1) break;
		
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c));
		
		
		
	}
	return 0;
}