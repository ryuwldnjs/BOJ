#include <iostream>
#include <stack>
using namespace std;
int n,com,x;
stack<int> s;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false); 
	cin>>n;
	while(n--){
		cin>>com;
		if(com == 1){
			cin>>x;
			s.push(x);
		}
		else if(com == 2){
			if(s.empty()){
				cout<<-1<<'\n';
				continue;
			}
			cout<<s.top()<<'\n';
			s.pop();
		}
		else if(com == 3) cout<<s.size()<<'\n';
		else if(com == 4) cout<<s.empty()<<'\n';
		else if(com == 5) {
			if(s.empty()) cout<<-1<<'\n';
			else cout<<s.top()<<'\n';
		}
	}
	return 0;
}