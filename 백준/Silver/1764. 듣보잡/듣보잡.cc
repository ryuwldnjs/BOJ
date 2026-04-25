#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string name;
map<string, bool> dic;
vector<string> list;
int n,m;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>name;
		dic[name] = true;
	}
	for(int i=0;i<m;i++){
		cin>>name;
		if(dic[name]) list.push_back(name);
	}
	
	sort(list.begin(), list.end());
	
	cout<<list.size()<<'\n';
	for(int i=0;i<list.size();i++) cout<<list[i]<<'\n';
	return 0;
}