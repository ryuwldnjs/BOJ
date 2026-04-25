#include <iostream>
#include <algorithm>
using namespace std;
int n,m,num;
int arr[500000+50];
int cnt[500000+50];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(true); 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cin>>m;
	while(m--){
		cin>>num;
		cout<<upper_bound(arr,arr+n,num) - lower_bound(arr,arr+n,num)<<" ";
	}
	return 0;
}