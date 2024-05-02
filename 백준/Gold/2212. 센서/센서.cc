#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int n,k,answer;
vector<int> arr, gap;
int main(){
	cin>>n>>k;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(), arr.end());
	
	for(int i=1;i<n;i++){
		gap.push_back(arr[i] - arr[i-1]);
	}
	sort(gap.begin(), gap.end());
	
	for(int i=0;i<n-k && i<gap.size();i++){
		answer += gap[i];
	}
	
	cout<<answer;
	return 0;
}