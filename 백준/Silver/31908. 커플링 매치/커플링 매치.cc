#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
using pss=pair<string,string>;
int n;
string name, ring;
vector<pss> answer;
map<string, vector<string>> m;
int main(){
	cin>>n;
	while(n--){
		cin>>name>>ring;
		if(ring == "-") continue;
		m[ring].push_back(name);
	}
	for(auto it = m.begin(); it!=m.end();it++){
		vector<string> &tmp = it->second;
		if(tmp.size() == 2){
			answer.push_back({tmp[0], tmp[1]});
		}
	}
	cout<<answer.size()<<'\n';
	for(auto &i : answer){
		cout<<i.first<<' '<<i.second<<'\n';
	}
	return 0;
}