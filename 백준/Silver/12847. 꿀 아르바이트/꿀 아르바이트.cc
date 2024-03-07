#include <bits/stdc++.h>
using namespace std;
long long n,m,answer;
long long psum[100000+5];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>psum[i];
		psum[i] += psum[i-1];
	}
	
	for(int i=m;i<=n;i++){
		answer = max(answer, psum[i] - psum[i-m]);
	}
	cout<<answer;
	return 0;
}