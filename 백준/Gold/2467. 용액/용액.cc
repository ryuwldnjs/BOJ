#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[100000+5];
int ans=2100000000;
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];//정렬됨을 보장함 
	
	int l=0, r=n-1;
	int ans_l, ans_r;
	while(l<r){
		int sum = arr[l] + arr[r];
		
		if(abs(sum) < ans){
			ans = abs(sum);
			ans_l = arr[l];
			ans_r = arr[r];
		}
		if(sum<0) l++;
		else r--;
		
	}
	cout<<ans_l<<' '<<ans_r;
	
	return 0;
}