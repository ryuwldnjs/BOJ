#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<long long> arr;
int main(){
	cin>>n>>k;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(), arr.end());
	
	long long answer = arr.back();
	k--;
	for(int i=0;i<(arr.size()-1)/2 && i<k/2;i++){
		answer += arr[arr.size()-2-i] - arr[i];
	}
	cout<<answer;
	return 0;
}