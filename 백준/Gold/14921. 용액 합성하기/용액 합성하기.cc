#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int n,answer,MIN=1e9;
int main(){
	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++){
		int target = lower_bound(arr.begin()+i+1, arr.end(), -arr[i]) - arr.begin();
		
		if(target < n && abs(arr[i]+arr[target]) < MIN){
			answer = arr[i]+arr[target];
			MIN = abs(arr[i]+arr[target]);
		} 
		if(target-1 > i && abs(arr[i]+arr[target-1]) < MIN){			
			answer = arr[i]+arr[target-1];
			MIN = abs(arr[i]+arr[target-1]);
		}
	}
	cout<<answer;
	return 0;
}