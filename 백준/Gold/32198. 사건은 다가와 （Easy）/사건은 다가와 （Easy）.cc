#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
#define OFFSET 1000
using namespace std;
struct Info{
	int t,a,b;
	
	bool operator<(const Info& other) const{
		return t < other.t;
	}
};
vector<Info> arr;
vector<vector<int>> dp;
int n, MIN=INF;
int main(){
	cin>>n;
	dp.resize(n+1, vector<int>(2000+5, INF));
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		arr.push_back({a,b+OFFSET,c+OFFSET});
	}
	arr.push_back({0, -1+OFFSET, 1+OFFSET});
	sort(arr.begin(), arr.end());
	
	dp[0][0+OFFSET] = 0;
	for(int i=1;i<arr.size();i++){
		for(int j=0;j<=2000;j++){
			if(arr[i].a < j&&j < arr[i].b) continue; // 바디뱅
			 
			int range = arr[i].t - arr[i-1].t;		
			for(int k=0;k<=range;k++){
				if(j-k >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-k] + k);
				if(j+k <= 2000) dp[i][j] = min(dp[i][j], dp[i-1][j+k] + k);	
			}
		}
	}
	
	for(int i=0;i<=2000;i++){
		MIN = min(MIN, dp[n][i]);
	}
	cout<<(MIN==INF ? -1 : MIN);
	return 0;
}