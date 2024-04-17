#include <iostream>
#include <algorithm>
using namespace std;
int n,a,b;
vector<int> arr;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		arr.push_back(a-b);
	}
	sort(arr.begin(), arr.end());
	int answer = arr[n/2] - arr[(n-1)/2] + 1;
	cout<<answer;
	return 0;
}