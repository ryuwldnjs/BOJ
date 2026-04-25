#include <iostream>
#define INF 1234567890
using namespace std;
int t,n,arr[505], psum[505];
int dp[505][505];
// dp[i][j] : i~j까지 파일들을 하나로 합치는데 드는 비용 
int solve(int a, int b){
	
    //기저사례 : 파일 한개일경우
	if(a==b) return 0;
	//기저사례 : 파일 두개 한 묶음 일경우
	//if(a+1 == b) return arr[a]+arr[b];
	
	int &ret = dp[a][b];
	if(ret != -1) return ret;
	ret = INF;
	
	for(int i=a;i<b;i++)
		ret = min(ret, solve(a, i) + solve(i+1, b));
	
	ret += psum[b] - psum[a-1];
	return ret;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			psum[i] = psum[i-1] + arr[i];
		}
		
		for(int i=0;i<=n;i++) fill(dp[i], dp[i]+n+1, -1);
		cout<<solve(1, n)<<'\n';
	}
	return 0;
}