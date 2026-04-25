#include <iostream>
using namespace std; 
int a,b,c;
int main(){
	cin>>a>>b>>c;
	if(c<=b) cout<<"-1";
	else cout<<a/(c-b)+1;
	return 0;
}