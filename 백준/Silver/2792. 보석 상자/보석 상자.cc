#include <bits/stdc++.h>
using namespace std;
int n,m,arr[300000+5];
bool able(int x){
	int given = 0;
	for(int i=0;i<m;i++){
		given += (arr[i]-1) / x + 1;
	}
	return given <= n;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}
	long long l = 1;
	long long r = 2e9;
	for(int i=0;i<200;i++){
		long long mid = (l+r)/2;
		if(able(mid)) r = mid;
		else l = mid+1;
	}
	cout<<l;
	return 0;
}