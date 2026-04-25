#include <iostream>
using namespace std;
int n,q,arr[200000+5], sum[200000+5],x, total;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		sum[i] = arr[i]*arr[(i+1)%n]*arr[(i+2)%n]*arr[(i+3)%n];
		total += sum[i];
	}
	for(int i=0;i<q;i++){
		cin>>x;
		x--;
		total -= 2*(sum[(x-3+n)%n]+sum[(x-2+n)%n]+sum[(x-1+n)%n]+sum[x%n]);
		sum[(x-3+n)%n]*=-1;
		sum[(x-2+n)%n]*=-1;
		sum[(x-1+n)%n]*=-1;
		sum[x%n]*=-1;
		cout<<total<<'\n';
	}
	return 0;
}