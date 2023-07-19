#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, bool> set;
int n,m,cnt;
string str;
int main(){
	cin>>n>>m;
	while(n--){
		cin>>str;
		set[str] = true;
	}
	while(m--){
		cin>>str;
		if(set[str]) cnt++;
	}
	cout<<cnt;
	return 0;
}