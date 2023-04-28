#include <iostream>
#define INF 1000000000
using namespace std;
int a,n,k;
int psum[100000+50];

int MAX = -INF;
int main(){
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a;
		psum[i] = psum[i-1] + a;
	}
	
	for(int i=k; i<=n;i++){
		MAX = max(MAX, psum[i] - psum[i-k]);
	}
	
	cout<<MAX;
	return 0;
}