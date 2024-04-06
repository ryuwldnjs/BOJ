#include <iostream>
#include <unordered_map>
using namespace std;
long long n,arr[200000+5], MAX=1;
unordered_map<long long, long long> m;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		MAX = max(MAX, ++m[arr[i]]);
	}
	for(int i=0;i<n;i++){
		for(long long bit = 1; bit<32;bit++){
			if((arr[i]<<bit) > 1000000000LL) break;
			if(m.count(arr[i]<<bit)){
				MAX = max(MAX, ++m[(arr[i]<<bit)]);
			}
		}
	}
	cout<<MAX;
	return 0;
}