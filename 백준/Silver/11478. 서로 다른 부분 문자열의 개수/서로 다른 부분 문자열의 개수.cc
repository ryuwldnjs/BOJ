#include <iostream>
#include <string>
#include <map>
using namespace std;

string str,sub;
map<string, bool> m;
int main(){
	cin>>str;
	for(int i=0;i<str.size();i++){
		for(int j=1;i+j<=str.size();j++){
			sub = str.substr(i, j);
		//	cout<<sub<<' ';
			m[sub] = true;
		}
	}
	cout<<m.size();
	return 0;
}