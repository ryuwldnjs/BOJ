#include <iostream>
using namespace std;
int prefix[100000+5];
int n,m, num, a,b;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num;
		if(i==1) prefix[i] = num;
		else prefix[i] = num + prefix[i-1]; 
	}
	for(int i=0;i<m;i++){
		cin>>a>>b; //구간 [a, b]
		cout<<prefix[b]-prefix[a-1]<<'\n';
	}
	return 0;
}