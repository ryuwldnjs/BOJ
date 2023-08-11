#include <iostream>
using namespace std;
long long m,command, SUM,XOR, x;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>m;
	while(m--){
		cin>>command;
		if(command == 1){
			cin>>x;
			SUM += x;
			XOR ^= x;	
		}
		else if(command == 2){
			cin>>x;
			SUM -= x;
			XOR ^= x;	
		}
		else if(command == 3)
			cout<<SUM<<'\n';
		else
			cout<<XOR<<'\n';
		
		
	}
	return 0;
}