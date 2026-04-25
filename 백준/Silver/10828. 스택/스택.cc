#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> s;
string cmd;
int n,k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		cin>>cmd;
		
		if(cmd == "push"){
			cin>>k;
			s.push(k);
		}
		else if(cmd == "pop"){
			if(s.empty()){
				cout<<"-1\n";
				continue;
			}
			cout<<s.top()<<'\n';
			s.pop();
		}
		else if(cmd == "size")
			cout<<s.size()<<'\n';
		else if(cmd == "empty")
			cout<<s.empty()<<'\n';
		else if(cmd == "top"){
			if(s.empty()) cout<<"-1\n";
			else cout<<s.top()<<'\n';
		}
	}
	return 0;
} 