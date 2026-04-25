#include <iostream>
#include <algorithm>
using namespace std;
int arr[5000+5];
long long ans_min = 3*1000000000LL+5LL;
long long first, second, third;
int ans[3];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr, arr+n);
	
	for(int i=0;i<n-2;i++){
		first = arr[i];
		int left = i+1, right = n-1;
		while(left<right){
			second = arr[left], third = arr[right];
			
			if(abs(first+second+third)<ans_min){
				ans_min = abs(first+second+third);
				ans[0]=first, ans[1]=second, ans[2]=third;
			}
			if(first+second+third<0) left++;
			else right--;
			
		}
		
	}
	cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2];
	return 0;
}