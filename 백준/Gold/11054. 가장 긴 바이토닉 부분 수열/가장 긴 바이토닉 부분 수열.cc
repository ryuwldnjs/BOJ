#include <iostream>
using namespace std;
int n,arr[1005];
int increase[1005], decrease[1005];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	fill(increase, increase+n, 1);
	fill(decrease, decrease+n, 1);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[j] > arr[i]) increase[j] = max(increase[j], increase[i]+1);
		}
	}
	
	for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			if(arr[j] > arr[i]) decrease[j] = max(decrease[j], decrease[i]+1);
		}
	}
	int MAX=0;
	for(int i=0;i<n;i++)
		MAX = max(MAX, increase[i]+decrease[i]-1);
	cout<<MAX;
	return 0;
}