#include <iostream>
#include <algorithm>
using namespace std;

int n,q,arr[300000+5], psum[300000+5], a,b;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	for(int i=1;i<=n;i++){
		psum[i] = psum[i-1] + arr[i-1];
	}
	
	while(q--){
		cin>>a>>b;
		
		cout<<psum[b] - psum[a-1]<<'\n';
	}
	return 0;
}