#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000000+5];
int n;
bool cmp(int a, int b){
	return a > b;
} 
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr, arr+n, cmp);
	
	for(int i=0;i<n;i++) cout<<arr[i]<<'\n';
	return 0;
}