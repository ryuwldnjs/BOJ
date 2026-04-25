#include <iostream>
#include <set>
#include <string>
using namespace std;
set<int> s;
set<int>::iterator it;
int m,x;
string cmd;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>m;
	while(m--){
		cin>>cmd;
		if(cmd == "add"){
			cin>>x;
			s.insert(x);
		}
		else if(cmd == "remove"){
			cin>>x;
			s.erase(x);
		}
		else if(cmd == "check"){
			cin>>x;
			it = s.find(x);
			if(it != s.end()) cout<<"1\n";
			else cout<<"0\n";
		}
		else if(cmd == "toggle"){
			cin>>x;
			it = s.find(x);
			if(it != s.end()) s.erase(it);
			else s.insert(x);
		}
		else if(cmd == "all"){
			for(int i=1;i<=20;i++) s.insert(i);
		}
		else if(cmd == "empty"){
			s.clear();
		}
		
	}
	return 0;
}