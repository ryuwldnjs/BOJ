#include <iostream>
using namespace std;
int n,a;
int approve, reject, invalid;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a == 1) approve++;
		else if(a == -1) reject++;
		else invalid++;
	}
	
	if(invalid >= (n+1)/2) cout<<"INVALID";
	else if(reject >= approve) cout<<"REJECTED";
	else cout<<"APPROVED";
	return 0;
}