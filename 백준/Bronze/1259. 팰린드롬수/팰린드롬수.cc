#include<iostream>
#include <string>
using namespace std;
string n;
int main(){
	while(1){
		cin>>n;
		int sz = n.size();
		
		if(n == "0") return 0;
		
		for(int i=0;i< sz/2 ;i++){
			if(n[i] != n[sz-i-1]){
				cout<<"no\n";
				goto bolbbalgan4choonki;
			}
		}
		
		cout<<"yes\n";
		bolbbalgan4choonki:;
	}
	
	return 0;
}