#include <iostream>
using namespace std;

int s,e,n,m,a, prefix[100000+5];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(i) prefix[i] = prefix[i-1] + a;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>s>>e;
		cout<<prefix[e]-prefix[s-1]<<"\n";
	}
	return 0;
}