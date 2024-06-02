#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string a,b,c;
int d,e;
int n;

vector<pair<int, string>> cand;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c>>d>>e;
		if(b == "hewhak") continue;
		if(c == "winner") continue;
		if(1<=d&&d<=3) continue;
		cand.push_back({e, a});
	}
	sort(cand.begin(), cand.end());
	vector<string> answer;
	for(int i=0;i<cand.size() && i<10;i++){
		answer.push_back(cand[i].second);
//		cout<<cand[i].first<<'\n';
	}
	
	cout<<answer.size()<<'\n';
	sort(answer.begin(), answer.end());
	for(auto a :answer){
		cout<<a<<'\n';
	}
	return 0;
}