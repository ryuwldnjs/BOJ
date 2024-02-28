#include <bits/stdc++.h>
using namespace std;
long long n,m, MIN = 2e9;
vector<long long>arr;
int main(){
	cin>>n>>m;
	arr.resize(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr.begin(), arr.end());
	for(int i=0;i<n;i++){
		int idx = lower_bound(arr.begin()+i, arr.end(), arr[i] + m) - arr.begin();
		if(idx == n) continue;
		MIN = min(MIN, arr[idx] - arr[i]);
	}
	cout<<MIN;
	return 0;
}