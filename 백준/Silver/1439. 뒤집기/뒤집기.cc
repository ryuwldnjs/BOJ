#include <iostream>
#include <string>
using namespace std;
string s;
int toggle;
int main(){
	cin>>s;
	int sz = s.size();
	
	for(int i=0;i<sz-1;i++){
		if(s[i] != s[i+1]) toggle++;
	}
	
	cout<<(toggle+1)/2;
	return 0;
}