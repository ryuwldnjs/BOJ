#include <iostream>
#define INF 1234567890
using namespace std;
int n,k,b,x;
int map[100000+5], psum[100000+5];
int MIN = INF;
int main(){
	cin>>n>>k>>b;
	
	for(int i=0;i<b;i++){
		cin>>x;
		map[x] = 1;
	}
	for(int i=1;i<=n;i++){
		psum[i] = psum[i-1] + map[i];
		
		int broken = i-k>=0 ? psum[i] - psum[i-k] : 100000000;
		MIN = min(MIN, broken);
	}
	cout<<MIN;
	
	return 0;
}