#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000+5];
int ans_min=0x7FFFFFFF, ans_first, ans_second;
int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++) cin>>arr[i];
	
	sort(arr, arr+n);
	
	
	for(int i=0;i<n-1;i++){
		int first = arr[i]; // first + second = 0에 근접 
		int idx = lower_bound(arr+i+1, arr+n, -first) - arr;
		
		if(idx==n) idx=n-1; //
		else if(idx>i+1 && abs(arr[idx]+first) > abs(arr[idx-1]+first))
			idx = idx-1; 
		
		
		int second = arr[idx];
		
		
		if(abs(first+second)<ans_min){
			ans_min = abs(first+second);
			ans_first = first;
			ans_second = second;
		}
		
		
	}
	
	
	cout<<ans_first<<' '<<ans_second;
	return 0;
}