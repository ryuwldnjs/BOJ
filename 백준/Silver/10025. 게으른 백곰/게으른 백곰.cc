#include <iostream>
#include <vector>
#define INF 1000000
using namespace std;

long long psum[1000000+50];
long long n,k,a,b,map[1000000+50];
long long MAX = -1; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	k = 2*k>INF ? INF/2 : k;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		map[b] = a;
	}
	psum[0] = map[0];
	for(int i=1;i<=INF;i++){
		psum[i] = psum[i-1] + map[i];
	}
	
	
	for(int i=2*k;i<=INF;i++){
		long long sum = psum[i];
		if(i>2*k) sum -= psum[i - 2*k-1];
		
		MAX = max(MAX, sum);
	}
	cout<<MAX;
	return 0;
}