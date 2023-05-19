#include <iostream>
#define INF 1234567890
using namespace std;

int t, n, a, psum[1000+5]; 
int MAX;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>t;
	
	while(t--){
		MAX = -INF;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a;
			psum[i] = psum[i-1] + a;
		}
		
		for(int i=0;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				MAX = max(MAX, psum[j] - psum[i]);
			}
		}
		cout<<MAX<<'\n';
	}
	return 0;
}