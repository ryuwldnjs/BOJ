#include <iostream>
using namespace std;
int n,m;
int psum[1005][1005];
int dp[1005][1005]; 
//dp[i][j] : (i,j) 가 우측 하단인 정사각형의 최대 한변 사이즈 
int MAX;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c; cin>>c;
			int num = c - '0';
			psum[i][j] = num 
						+ psum[i-1][j]
						+ psum[i][j-1] 
						- psum[i-1][j-1];
			dp[i][j] = num;
			
			for(int size=dp[i-1][j-1]; size>=0;size--){
				int square_sum = psum[i][j] 
								- psum[i-size-1][j]
								- psum[i][j-size-1]
								+ psum[i-size-1][j-size-1];
						
				if(square_sum == (size+1)*(size+1)){
					dp[i][j] = size + 1;
					MAX = max(MAX, dp[i][j]);
					break;
				}
			}
		}
	}
	cout<<MAX*MAX;
	return 0;
}