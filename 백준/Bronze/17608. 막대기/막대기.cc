#include <iostream>
using namespace std;
int n,maximum,cnt,arr[100000+5];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	for(int i=n-1;i>=0;i--){
		if(arr[i]>maximum){
			maximum = arr[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}