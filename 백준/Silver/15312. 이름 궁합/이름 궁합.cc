#include <iostream>
#include <string>
using namespace std;
int dp[4005][4005]; //dp[i][j] : i스테이지의 j번째 값 
int init[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
string a,b;
int main(){
	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		dp[0][2*i] = init[a[i] - 'A'];
		dp[0][2*i+1] = init[b[i] - 'A'];
	}
	int n = a.size()*2;
	for(int i=1;i<n-1;i++){
		for(int j=0;j<n-i;j++){
			dp[i][j] = (dp[i-1][j] + dp[i-1][j+1]) % 10;
		}
	}
	cout<<dp[n-2][0]<<dp[n-2][1];
	return 0;
}