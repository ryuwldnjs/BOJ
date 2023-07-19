#include <iostream>
#include <map> 
#include <string>
using namespace std;

int n;
string name, state;
map<string, bool, greater<string>> log;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>name>>state;
		if(state == "enter")
			log[name] = true;
		else
			log[name] = false;
	}
	for(auto it = log.begin(); it != log.end(); it++){
		if(it->second) cout<<it->first<<'\n';
	}
	return 0;
}