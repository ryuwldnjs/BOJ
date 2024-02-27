#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> idx;
int n,x, MAX;
int main(){
	cin>>n;
	vector<int> dp(n+1,1);
	for(int i=1;i<=n;i++) {
		cin>>x;
		idx[x] = i;
		if(idx[x-1]) dp[i] = max(dp[idx[x-1]]+1, dp[i]);
	}

	for(int i=1;i<=n;i++) MAX = max(MAX, dp[i]);
	cout<<MAX;
	return 0;
}