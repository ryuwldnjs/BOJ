#include <iostream>
#include <algorithm>
#define INF 1234567890
using namespace std;
int n,s, a;
int arr[100000+5];
int main(){
	cin>>n>>s;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int l=0, r=0, sum=arr[0];
	int MIN = INF;
	while(l<=r && r<n){
		int gap = r-l+1;
		
		if(sum < s){
			r++;
			sum += arr[r];
		}
		else{
			MIN = min(MIN, gap);
			sum -=arr[l];
			l++;
		}
	}
	if(MIN==INF) cout<<'0';
	else cout<<MIN;
	return 0;
}