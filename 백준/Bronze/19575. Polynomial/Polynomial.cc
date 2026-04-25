#include <iostream>
#define MOD 1000000007
using namespace std;

long long n,x,poly[1000000+5], sum,a,b;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>x;
	
	for(int i=0;i<n+1;i++){
		cin>>a>>b;
		poly[b] = a;
	}
	
	sum = poly[n]%MOD;
	for(int i=n-1;i>=0;i--){
		sum = x*sum + poly[i];
		sum = sum%MOD;
	}
	cout<<sum;
	return 0;
}