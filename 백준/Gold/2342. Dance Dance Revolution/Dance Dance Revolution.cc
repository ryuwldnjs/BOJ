#include <iostream>
#include <vector>
#define INF 100000000
using namespace std;

int dp[100005][5][5]; //dp[step][left][right] : step단계일때 left,right발위치 일때 최소 비용 
int n, answer = INF;
vector<int> step;
int score(int prev, int now){
	if (now == 0) return INF; //에러 
	if(prev == now) return 1;
	if(prev == 0) return 2;
	prev--;
	now--;
	
	if((prev+1)%4 == now || (prev+3)%4 == now) return 3;
	return 4;
}

int main(){
	while(true){
		cin>>n;
		if(n == 0) break;
		step.push_back(n); // 
	}
	n = step.size();
	if(n == 0){
		cout<<0;
		return 0;
	}
	int start = step[0];
	fill(&dp[0][0][0], &dp[100004][4][4], INF);
	dp[0][start][0] = dp[0][0][start] = 2;
	
	for(int i=1;i<n;i++){
		int now = step[i];
		for(int l=0;l<5;l++){
			for(int r=0;r<5;r++){
					dp[i][now][r] = min(dp[i][now][r], dp[i-1][l][r] + score(l, now));
					dp[i][l][now] = min(dp[i][l][now], dp[i-1][l][r] + score(r, now));
			}
		}
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			answer = min(answer, dp[n-1][i][j]); 
		}
	}
	cout<<answer;
	return 0;
}