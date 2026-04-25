#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

map<string, int> dic_name;
vector<string> dic_idx(100000+10);
string name;

int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>name;
		dic_name[name] = i;
		dic_idx[i] = name;
	}
	
	for(int i=0;i<m;i++){
		cin>>name;
		if(isdigit(name[0])){
			int num = atoi(name.c_str());
			cout<<dic_idx[num]<<'\n';
		}
		else{
			cout<<dic_name[name]<<'\n';
		}
	}
	return 0;
}