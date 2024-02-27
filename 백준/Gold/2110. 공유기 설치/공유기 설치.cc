#include <iostream>
#include <algorithm>
using namespace std;
int n,c;
int arr[200000+5];

bool able(int x){
	int router=1; //설치된 공유기 수 
	//idx=0인곳에 항상 공유기 설치를 한다
	
	int prev = 0;//바로 이전에 공유기를 설치한 곳 
	for(int i=1;i<n;i++){
		if(arr[prev] + x <= arr[i]){
			router++;
			prev = i;
		}
		
		//공유기를 전부다 설치했으면 true 
		if(router == c) return true;
	}
	return false;
}
int main(){
	cin>>n>>c;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr, arr+n);
	
	//이분법 - 100번 국룰 
	int lo=0, hi=arr[n-1];  
	for(int it=0;it<100;it++){
		int mid = (lo+hi)/2;
		
		if(able(mid))
			lo = mid;
		else
			hi = mid-1;
	}
	int answer = able(hi) ? hi : lo;
	cout<<answer;
    return 0;
}