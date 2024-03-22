#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string s;
	vector<string> list;
	cin>>s;
	for(int i=0;i<s.size();i++){
		list.push_back(s.substr(i));
	}
	sort(list.begin(), list.end());
	for(auto s : list){
		cout<<s<<'\n';
	}
	return 0;
}