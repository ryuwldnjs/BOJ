#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,x,answer;
vector<int> arr;
int main(){
	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cin>>x;
	sort(arr.begin(), arr.end());
	
	for(int i=0;i<n;i++){
		if(binary_search(arr.begin()+i+1, arr.end(), x-arr[i]))
			answer++;
	}
	cout<<answer;
	return 0;
}