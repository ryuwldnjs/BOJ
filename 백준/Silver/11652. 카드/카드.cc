#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100000+5];
long long n,ans_cnt,ans_num, cnt=1;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	
	ans_cnt=1, ans_num=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]==arr[i-1]) cnt++;
		else{
			cnt=1;
		}
		
		if(cnt>ans_cnt){
			ans_cnt = cnt;
			ans_num = arr[i];
		}
	}
	cout<<ans_num;
	return 0;
}