#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n,cnt;
string str;
int main(){
	cin>>n;
	while(n--){
		cin>>str;
		stack<char> s;
		s.push(NULL);
		
		for(int i=0;i<str.size();i++){
			char top = s.top();
			if(top == str[i])
				s.pop();
			else
				s.push(str[i]);
		}
		
		if(s.top() == NULL) cnt++; 
		
	}
	
	cout<<cnt;
	return 0;
}