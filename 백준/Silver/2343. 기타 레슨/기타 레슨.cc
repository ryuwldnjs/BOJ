#include <bits/stdc++.h>
using namespace std;
int n,m,arr[100000+5];

bool able(long long capacity){
	int cnt=1;
	int x=0;
	for(int i=0;i<n;i++){
		if(arr[i] > capacity) return false;
		x += arr[i];
		if(x > capacity){
			cnt++;
			x = arr[i];
		}
	}
	return cnt <= m;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int l = 1;
	int r = 2e9;
	for(int i=0;i<200;i++){
		int mid = (l+r)/2;
		if(able(mid)) r = mid;
		else l = mid+1;
	}
	cout<<l;
	return 0;
}