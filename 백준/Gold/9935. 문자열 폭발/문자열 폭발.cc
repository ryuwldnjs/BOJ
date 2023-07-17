#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

string str, explosion;
int idx[200];

stack<int> s, s2;
vector<char> answer;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>str;
	cin>>explosion;
	fill(idx, idx+200, -1);
	int str_sz = str.size();
	int ex_sz = explosion.size();
	
	for(int i=0;i<explosion.size();i++){
		idx[explosion[i]]=i;
	}
	
	for(int i=0;i<str.size();i++){
		if(idx[str[i]] != -1)
			s.push(idx[str[i]]);
		else s.push(-1);
		s2.push(str[i]);
		
		
		if(idx[str[i]] == explosion.size()-1){//폭발문자열 마지막 글자 
			stack<int> tmp,tmp2;
			int sz = explosion.size() - 1;
			while(sz > -1 && !s.empty()){
				int top = s.top();
				int top2 = s2.top();
				s.pop();
				s2.pop();
				tmp.push(top);
				tmp2.push(top2);
				if(top != sz)
					break;
				sz--;
			}
			if(sz != -1){//안터지니까 되돌리기 
				while(!tmp.empty()){
					s.push(tmp.top());
					s2.push(tmp2.top());
					tmp.pop();
					tmp2.pop();
				}
			}	
		}
		
	}
	if(s2.empty()) cout<<"FRULA";
	while(!s2.empty()){
		answer.push_back(s2.top());
		s2.pop();
	}
	for(int i=answer.size()-1;i>=0;i--){
		cout<<answer[i];
	}
	return 0;
}