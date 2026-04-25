#include <iostream>
#include <algorithm>
using namespace std;
int n,arr[1000000+5];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++) cout<<arr[i]<<"\n";
	return 0;
}