#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>
using namespace std;

map<int, int> compress;
vector<int> arr;
int n,k;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		arr.push_back(k);
		
	}
	vector<int> ans = arr;
	
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for(int i=0;i<arr.size();i++){
		compress[arr[i]] = i; //좌표압축
	}
	for(int i=0;i<n;i++){
		cout<<compress[ans[i]]<<' ';
	} 
	return 0;
} 