#include <iostream>
#include <algorithm>
using namespace std;

int p,n;
int arr[1005];
int main(){
	cin>>p>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	sort(arr, arr+n);
	
	for(int i=0;i<n;i++){
		if(p >= 200){
			cout<<i;
			return 0;
		}
		p += arr[i];
		//printf("%d\n", p);
	}
	cout<<n;
	return 0;
}