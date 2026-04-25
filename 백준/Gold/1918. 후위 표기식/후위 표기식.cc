#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;
string infix, postfix;
int level(char op){
	switch(op){
		case '*':
			return 100;
		case '/':
			return 100;
		case '+':
			return 10;
		case '-':
			return 10;
		case '(':
			return 1;
		default:
			return 0;
	}
	
}
bool IsOperator(char x){
	if(x == '*' || x == '/' || x == '+' || x == '-' || x == '(')
		return true;
	return false;
}
int main(){
	cin>>infix;
	
	for(int i=0;i<infix.size();i++){
		//괄호는 일단 넣어 
		if(infix[i] == '(') s.push(infix[i]);
		//닫는 괄호를 만났을때 
		else if(infix[i] == ')'){
			while(s.top() != '('){ //여는 괄호 만날떄까지 
				postfix += s.top();
				s.pop();
			}
			s.pop(); //괄호까지 삭제 
		}
		else if(IsOperator(infix[i])){
			while(!s.empty() && level(s.top()) >= level(infix[i])){
				postfix += s.top();
				s.pop();
			}
			s.push(infix[i]);
		}
		else{ //피연산자일때 
			postfix += infix[i];
		}
	}
	while(!s.empty()){
		postfix += s.top();
		s.pop();
	}
	cout<<postfix;
	return 0;
}