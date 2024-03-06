#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<long long> a(n+1), psum(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		psum[i] = psum[i-1] + a[i];
	}
	
	//벌(1),꿀통,벌(n) 
	long long answer = psum[n-1] - psum[1] + *max_element(a.begin(), a.end());
	//벌(1),벌,꿀통(n)
	for(int i=2;i<n;i++){
		answer = max(answer, 2*psum[n] - psum[i] - psum[1] - a[i]);
	}
	//꿀통(1), 벌, 벌(n)
	for(int i=2;i<n;i++){
		answer = max(answer, psum[n-1] + psum[i-1] - a[i]);
	}	 
	cout<<answer;
	return 0;
}