#include <iostream>
#include <string>
#include <map>

using namespace std;
map<string, string> pw;
string domain, password;
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>domain>>password;
		pw[domain] = password;
	}
	
	for(int i=0;i<m;i++){
		cin>>domain;
		cout<<pw[domain]<<'\n';
	}
	return 0;
}