#include <iostream>
#include <string>
#include <stack>
using namespace std;
string str;
int cnt;
stack<char> s;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false); 
	
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='(') s.push('(');
		else{
			s.pop();
			if(str[i-1]=='(') cnt += s.size();
			else cnt++;
		}
	}
	cout<<cnt;
	return 0;
}