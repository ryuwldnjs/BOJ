#include <iostream>
using namespace std;
int k,a=1,b;
int main(){
	cin>>k;
	
	while(k--){
		int new_a = b;
		int new_b = a + b;
		a = new_a;
		b = new_b;
	}
	cout<<a<<' '<<b;
	return 0;
}