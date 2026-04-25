#include <iostream>
#include <algorithm>
using namespace std;

int arr[3]; 
int main(){
	while(1){
		cin>>arr[0]>>arr[1]>>arr[2];
		if(arr[0]+arr[1]+arr[2] == 0) return 0;
		sort(arr,arr+3);
		
		if(arr[2]*arr[2] == arr[1]*arr[1]+arr[0]*arr[0]) cout<<"right\n";
		else cout<<"wrong\n";
	}
	
	return 0;
}