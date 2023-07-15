#include <iostream>
#define INF 1000000001
using namespace std;
int n,m,a[1000000+5], b[1000000+5];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	a[n] = b[m] = INF;
	
	int i=0;
	int j=0;
	while(a[i]!=INF || b[j] !=INF){
		if(a[i] > b[j]){
			cout<<b[j]<<' ';
			j++;
		}
		else{
			cout<<a[i]<<' ';
			i++;
		}
	}
	
	return 0;
}