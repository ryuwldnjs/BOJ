#include <bits/stdc++.h>
using namespace std;
//nH2 = n+1C2
int n,arr[200000+5];
long long answer;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	arr[n] = -1;
	
	long long s = 0;
	for(int i=1;i<n+1;i++){
		s++;
		if(arr[i-1] >= arr[i]){
			answer += (s*s+s) / 2;
			s = 0;
		}
	}
	cout<<answer;
	return 0;
}