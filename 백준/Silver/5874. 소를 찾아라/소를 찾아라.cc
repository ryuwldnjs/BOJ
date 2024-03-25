#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str;
vector<int> back, front;
int answer;
int main(){
	cin>>str;
	for(int i=1;i<str.size();i++){
		if(str[i-1]=='(' && str[i]=='(') back.push_back(i);
		if(str[i-1]==')' && str[i]==')') front.push_back(i);
	}
	
	for(int now : back){
		int cnt = front.end() - lower_bound(front.begin(), front.end(), now);
		answer += cnt;
	}
	
	cout<<answer;
	return 0;
}