#include <iostream>

using namespace std;
int n,k;
int main(){
	cin>>n>>k;
	
	for(int i=0;;i++, n++){
		int tmp = n;
		int one=0;
		while(tmp){
			one += tmp%2;
			tmp/=2;
		}
		if(one <= k){
			cout<<i;
			return 0;
		}
	}
	return 0;
} 