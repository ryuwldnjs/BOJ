#include <iostream>
using namespace std;
long long sum,s;

int main(){
	cin>>s;
	
	for(long long i=1;i<1000000000;i++){
		sum += i;
		if(sum > s){
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}