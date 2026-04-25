#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;
vector<int> arr;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(), arr.end());
	cout<<arr[k-1];
	return 0;
}