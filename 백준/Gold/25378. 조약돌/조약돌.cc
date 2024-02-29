#include <bits/stdc++.h>
using namespace std;
int n,answer;
int arr[2500+5];
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	for(int i=1;i<n;i++){
		int MIN = min(arr[i], arr[i-1]);
		if(MIN == 0) continue;
		
		arr[i] -= MIN;
		arr[i-1] -= MIN;
		answer++;
	}
	for(int i=0;i<n;i++)
		if(arr[i]) answer++;
		
	cout<<answer;
	return 0;
}