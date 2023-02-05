#include <iostream>

using namespace std;
long long arr[10000+5], sum;
int n,m,ans;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int a=0,b=1;
	sum = arr[0];
	while(1){
//		printf("%d, %d: %d\n", a,b, sum);
		
		
		if(a >= n || b>n) break;
		if(sum == m) ans++;
		
		if(sum <= m){
			sum += arr[b];
			b++;
		}
		else{
			sum -= arr[a];
			a++;
		}
		
	}
	
	cout<<ans;
	return 0;
}