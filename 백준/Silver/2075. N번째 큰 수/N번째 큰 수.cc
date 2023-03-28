#include <iostream>
#include <algorithm> 
using namespace std;

int n, arr[1500*1500 + 100];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n*n;i++){
		cin>>arr[i];
	}
	sort(arr, arr+n*n);
	cout<<arr[n*n - n];
	return 0;
}